#include<stdio.h>

#define N 5	//Ҷ�ӽڵ���
#define MAX 2*N-1	//�ܽ����

typedef struct HNode{
	double weight;
	int flag;	//�����ڴ���ʱ��ʶ�Ƿ��ù�
	int parent,lchild,rchild;
}HNode;

void initHFT(HNode hfmtree[],int n);
int select(HNode hfmtree[],int n);
void crthfm(HNode hfmtree[],int n);
void printhfm(HNode hfmtree[],int n);

int main(){
	HNode hfmtree[MAX+1]; //0�ŵ�Ԫ����
	initHFT(hfmtree,N);		//��ʼ����������
	crthfm(hfmtree,N);//��ʼ��
	printf("������Ĺ�������Ϊ\n");
	printhfm(hfmtree,MAX);
}
void initHFT(HNode hfmtree[],int n){
	int i;
	for(i=1;i<=n;i++) //��ʼ��Ҷ�ӽڵ�
	{
		hfmtree[i].lchild=0;	
		hfmtree[i].rchild=0;	
		hfmtree[i].parent=0;	
		hfmtree[i].flag=0;
		printf("������%d��Ԫ�ص�Ȩֵ��\n",i);
		scanf("%lf",&hfmtree[i].weight);
		while (getchar() != '\n');
	}
	for(i=n+1;i<=MAX;i++)//��ʼ����Ҷ�ӽڵ�
    {
        hfmtree[i].lchild=0;
        hfmtree[i].rchild=0;
        hfmtree[i].weight=0;
        hfmtree[i].parent=0;
        hfmtree[i].flag=0;
    }
}

int select(HNode hfmtree[],int n){	//ѡ����СȨֵ�ڵ��±�
	int i,min;
	double temp;	//��Сֵ
	//����һ����Ϊ��ʼ����Сֵ
	for(i=1;i<=n;i++){
		if(hfmtree[i].flag==0){
			temp=hfmtree[i].weight;	//��ʼ��СȨֵ
			min =i;	//��ʼ���±�
			break;
		}
	}
	//Ѱ����С�±�
	for(i=1;i<=n;i++){
		if(hfmtree[i].flag==0&&hfmtree[i].weight<temp){
			temp=hfmtree[i].weight;
			min=i;
		}
	}
	//ѭ�������ҵ���Сֵ
	hfmtree[min].flag=1;
	return min;
}

void crthfm(HNode hfmtree[],int n){	//�γɹ�������
	int i;
	int index1,index2;
	for(i=n+1;i<=MAX;i++){
		index1=select(hfmtree,i-1);	//i-1����Ϊÿ�γ�һ�����ڵ�ԭ������һ��Ԫ��
		index2=select(hfmtree,i-1);
		hfmtree[i].weight=hfmtree[index1].weight+hfmtree[index2].weight;	//�½ڵ�Ȩֵ
		hfmtree[i].lchild=index1;	//�½ڵ�����Һ���
		hfmtree[i].rchild=index2;
		hfmtree[index1].parent=i;	//�γ�������С�ڵ�ĸ��ڵ�
		hfmtree[index2].parent=i;
	}
}

void printhfm(HNode hfmtree[],int n)//��ӡ��������
{   int i;
	printf("���  weigh  parent lchild rchild\n");
    for(i=1;i<=n;i++)
    {
        printf("%.d\t%.2f\t%d\t%d\t%d\n",i,hfmtree[i].weight,hfmtree[i].parent,hfmtree[i].lchild,hfmtree[i].rchild);
    }
    printf("\n");
}


