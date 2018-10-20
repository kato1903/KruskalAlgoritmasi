#include <stdio.h>
#include <stdlib.h>

typedef struct EDGE
{
	int u,v;
	int w;
}EDGE;

void Sort(EDGE arr[], int n)

{
   int i, j;
   EDGE tmp;
   for (i = 0; i < n-1; i++)      
 
       // Last i elements are already in place   
       for (j = 0; j < n-i-1; j++) 
           if (arr[j].w > arr[j+1].w)
           {
           		tmp = arr[j];
           		arr[j] = arr[j+1];
           		arr[j+1] = tmp;
		   }

}

int aktar(EDGE * gr, int matris[100][100],int n)
{
	int k=0,i,j;
	for(i=0;i<n;i++){
		for(j=i+1;j<n;j++){			
			if(matris[i][j]!=0){
				gr[k].u = i;
				gr[k].v = j;
				gr[k].w = matris[i][j];
				k++;
			}
		
		}
	}
	return k;
}

void yaz(int labelCount,int * label,int n)
{
	int d = 1;
	int i,j=0;
	while(d<=labelCount)
	{
		printf("\n%d. Gruptaki Dugumler",d);
		for(i=0;i<n;i++)
		{
			if(label[i]==d)
			{
				printf(" %d ",i);
			}
		}
		printf("\n");
		d++;
	}
}

int Kruskal(int kume,int k,int * label,int n,EDGE * gr)
{
	int i=0;
	int j=0;
	int kalanDugum = n;
	int labelCount = 0;
	int uu;
	int vv;
	while( (kalanDugum > 0) && (j < k) )
	{	
	
		if(kalanDugum != kume-labelCount)
		{
			
			uu=gr[j].u;
			vv=gr[j].v;
		
		if(label[uu]+label[vv]==0){
			if(labelCount<kume)
			{
			
			labelCount++;
			label[uu] = labelCount;
			label[vv] = labelCount;
			i++;
			j++;
			kalanDugum -= 2;
		}
		else
		{
			j++;	
		}
		}
		else
		{
			if(label[uu] == 0 || label[vv] == 0 )
			{
				if(label[uu]==0)
				{
					label[uu] = label[vv];
					i++;
					j++;
					kalanDugum--;
				}
				else
				{
					label[vv] = label[uu];
					i++;
					j++;
					kalanDugum--;
				}
			}
			else
			{
				j++;
			}
		}
	
	}
	else
	{
		for(i=0;i<n;i++)
			{
				if(label[i]==0)
				{
					labelCount++;
					label[i] = labelCount;
				}
			}
	}
		}
		
	
	return labelCount;
	
}

int oku(int matris[100][100])
{	
	int a,i=0,j=0;
	FILE * Dosya = fopen("data.txt","r");
		while(!feof(Dosya)){	
		fscanf(Dosya,"%d",&a);
		matris[i][j] = a;
		j++;
		if(fgetc(Dosya) != ',')
		{	
			i++;
			j = 0;
		}
	}	return i;
}

void Mesafe(int a,int b,EDGE gr[],int *label,int n,int son){
	
	int i,j,p;
	while(j<son)
	{	
		
		for(i=0;i<n;i++)
		{
			if( label[i]==a && i==gr[j].u)
				{
					for(p=0;p<n;p++)
					{
						 if(label[p]==b && p==gr[j].v)
						 	{
						 		printf("En Kisa Mesafe = %d \n%d ile %d Dugumleri arasinda",gr[j].w,gr[j].u,gr[j].v);
								 return;	
							}	
					}		
				}
		}
		
		for(i=0;i<n;i++)
		{
			if( label[i]==b && i==gr[j].u)
				{
					for(p=0;p<n;p++)
					{
						 if(label[p]==a && p==gr[j].v)
						 	{
						 		printf("En Kisa Mesafe = %d \n%d ile %d Dugumleri arasinda",gr[j].w,gr[j].u,gr[j].v);
								 return;	
							}	
					}		
				}
		}
		
		
		j++;
		}
	//	gr[i].u
	//	gr[i].v
		
	
	
	
}

int main(){
	

	
	int k=0,n;
	int i=0,j=0;
	int matris[100][100];
	int *label;
	int labelCount = 0;
	int uu;
	int vv;
	int kume;
	int kalanDugum;
	EDGE gr[100];
		
	n = oku(matris);
	k = aktar(gr,matris,n);
	Sort(gr,k);
	
	label = (int*) malloc (sizeof(int)*n);
	for(i=0;i<n;i++)
		label[i] = 0;
	printf("k sayisini giriniz");	
	scanf("%d",&kume);	
	labelCount = Kruskal(kume,k,label,n,gr);	
	yaz(labelCount,label,n);
	int a,b;
	printf("En Kisa Mesafe icin 2 Kume girin");
	scanf("%d %d",&a,&b);
	Mesafe(a,b,gr,label,n,k);
	
	
	return 0;
}
