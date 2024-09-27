#include<stdio.h>
#include<stdlib.h>
struct node{
	int data; 
	struct node *link;
};
typedef struct node NODE ; 

struct list{
	NODE *head ; 
	NODE *tail ; 
};
typedef struct list LIST ; 

void KhoiTao(LIST &l){
	l.head = l.tail = NULL; 
}

NODE *KhoiTaoNODE(int x){
	NODE *a = new NODE ; 
	if(a == NULL){
		printf("\nCap Phat Khong Thanh Cong "); 
		return NULL ;
	}
	a->data = x ; 
	a->link = NULL; 
	return a; 
	
}
void ThemDau(LIST &l ,NODE *a){
	if(l.head == NULL){
		l.head =l.tail = a; 
	}else 
		a->link = l.head;
		l.head = a ;
}

void ThemCuoi(LIST &l, NODE *a){
	if(l.head== NULL){
		l.head=l.tail=a;
	}else 
		l.tail->link = a ;
		l.tail =a ;
}

void Nhap(LIST &l, int n ){
	for(int i = 0 ; i< n; i++){
		int x; 
		printf("So nguyen : "); 
		scanf("%d",&x); 
		NODE *a = KhoiTaoNODE(x); 
		ThemCuoi(l,a); 
	}
}

void Xuat(LIST &l){
	for(NODE *k = l.head; k!=NULL; k=k->link){
		printf("\t%d",k->data);
	}
}

void ThemVaoVtriQ(LIST &l ,int x,int index){
	NODE *a = KhoiTaoNODE(x); 
	NODE *k = l.head ; 
	int count = 0 ;
	if(a == NULL)  return ; 
	if(index == 0){
		ThemCuoi(l,a);
		return ;
	}
	if(k->link == NULL){
		l.tail = a; 
	}
	while(k != NULL && count < index-1){
		k = k->link; 
		count ++; 
	}
	a->link = k->link;
	k->link =a; 
	
}


void XoaTatCa(LIST &l , int b){
	while(l.head != NULL && l.head->data == b){
		NODE *temp = l.head; 
		l.head = l.head->link;
		delete temp ;
	}
	if(l.head == NULL){
		l.tail= NULL ; return ;
	}
	
	NODE *k = l.head; 
	while(k->link != NULL){
		if(k->link->data == b){
			NODE *temp = k->link; 
			k->link= k->link->link; 
			delete temp;
		}else 
		  k = k->link ; 
	}
	
	if(k->link == NULL){
		l.tail = k; 
	}
}
void OutIndex(LIST &l ,int indexx){
	int d = 0 ;
	for( NODE *k = l.head; k != NULL; k=k->link){
		if(k->data == indexx){
			printf(" %d",d);
			return ;
		} d++;
	}
}
void Search(LIST &l ,int y){
	for( NODE *k = l.head; k != NULL; k=k->link){
		if(k->data == y){
			printf("Gia tri %d dc tim thay.\n",k->data);
			return ;
		} 
	}
}

void Max(LIST &l ){
	int max = 0 ;
	for( NODE *k = l.head; k != NULL; k=k->link){
		if(k->data > max ){
			max = k->data ;
		} 
	} printf("\nGia tri max trong DSLK la : %d",max);
}

void SapXepDSLK(LIST &l){
	if(l.head== NULL ) return ;
	for( NODE *i = l.head; i!=NULL; i= i->link){
		for( NODE *j = i->link; j!=NULL;j=j->link){
			if(i->data > j->data){
				int temp = i->data ;
				i->data = j->data ;
				j->data = temp; 
			}
		}
	}
}
int main(){
	LIST(l); 
	KhoiTao(l);
	int n ,indexx;
	scanf("%d",&n); 
	
	Nhap(l,n);
	Xuat(l);
	
	// VITRI
	printf("\nNhap vao gia tri can in ra vitri : ");
	scanf("%d",&indexx);
	OutIndex(l,indexx);
	
	// TIMKIEM
	int y;
	printf("\nNhap vao gia tri can tim : ");
	scanf("%d",&y);
	Search(l,y);
	
	// THEM VAO VITRI
	int x, index;
    printf("\nNhap gia tri can them: ");
    scanf("%d", &x);
    printf("Nhap vi tri can them: ");
    scanf("%d", &index);

    ThemVaoVtriQ(l, x, index);
    Xuat(l);
    
    // XOA THEO VITRI
    int b; 
    printf("\nNhap vao NODE can xoa b");
    scanf("%d",&b); 
    XoaTatCa(l,b);
    Xuat(l);
    
    // MAX 
    Max(l);
    
    // SapXepDSLK
    SapXepDSLK(l);
    printf("\nDSLK sau khi sap xep: ");
    Xuat(l);
    
    
    
     

}





