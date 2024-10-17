#include<stdio.h>

#define N 5	//叶子节点树
#define MAX 2*N-1	//总结点数

typedef struct HNode{
	double weight;
	int flag;	//用于在创建时标识是否被用过
	int parent,lchild,rchild;
}HNode;

void initHFT(HNode hfmtree[],int n);
int select(HNode hfmtree[],int n);
void crthfm(HNode hfmtree[],int n);
void printhfm(HNode hfmtree[],int n);

int main(){
	HNode hfmtree[MAX+1]; //0号单元不用
	initHFT(hfmtree,N);		//初始化哈夫曼树
	crthfm(hfmtree,N);//初始化
	printf("构建后的哈夫曼树为\n");
	printhfm(hfmtree,MAX);
}
void initHFT(HNode hfmtree[],int n){
	int i;
	for(i=1;i<=n;i++) //初始化叶子节点
	{
		hfmtree[i].lchild=0;	
		hfmtree[i].rchild=0;	
		hfmtree[i].parent=0;	
		hfmtree[i].flag=0;
		printf("请输入%d个元素的权值：\n",i);
		scanf("%lf",&hfmtree[i].weight);
		while (getchar() != '\n');
	}
	for(i=n+1;i<=MAX;i++)//初始化非叶子节点
    {
        hfmtree[i].lchild=0;
        hfmtree[i].rchild=0;
        hfmtree[i].weight=0;
        hfmtree[i].parent=0;
        hfmtree[i].flag=0;
    }
}

int select(HNode hfmtree[],int n){	//选择最小权值节点下标
	int i,min;
	double temp;	//最小值
	//先找一个作为初始的最小值
	for(i=1;i<=n;i++){
		if(hfmtree[i].flag==0){
			temp=hfmtree[i].weight;	//初始最小权值
			min =i;	//初始化下标
			break;
		}
	}
	//寻找最小下标
	for(i=1;i<=n;i++){
		if(hfmtree[i].flag==0&&hfmtree[i].weight<temp){
			temp=hfmtree[i].weight;
			min=i;
		}
	}
	//循环结束找到最小值
	hfmtree[min].flag=1;
	return min;
}

void crthfm(HNode hfmtree[],int n){	//形成哈夫曼树
	int i;
	int index1,index2;
	for(i=n+1;i<=MAX;i++){
		index1=select(hfmtree,i-1);	//i-1是因为每形成一个父节点原数组会多一个元素
		index2=select(hfmtree,i-1);
		hfmtree[i].weight=hfmtree[index1].weight+hfmtree[index2].weight;	//新节点权值
		hfmtree[i].lchild=index1;	//新节点的左右孩子
		hfmtree[i].rchild=index2;
		hfmtree[index1].parent=i;	//形成两个最小节点的父节点
		hfmtree[index2].parent=i;
	}
}

void printhfm(HNode hfmtree[],int n)//打印哈夫曼树
{   int i;
	printf("结点  weigh  parent lchild rchild\n");
    for(i=1;i<=n;i++)
    {
        printf("%.d\t%.2f\t%d\t%d\t%d\n",i,hfmtree[i].weight,hfmtree[i].parent,hfmtree[i].lchild,hfmtree[i].rchild);
    }
    printf("\n");
}


