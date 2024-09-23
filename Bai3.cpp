#include<stdio.h>
#include<stdlib.h>
struct node {
	int data ; 
	struct node *link; 
};
typedef struct node NODE; 

struct list{
	NODE *head ; 
	NODE *tail ; 
};
typedef struct list LIST; 

void KhoiTao(LIST &l){
	l.head = l.tail = NULL ;

}

NODE *KhoiTaoNode(int x){
	NODE *a = new NODE ; 
	if( a == NULL ){
		printf("\nKhong Cap Phat Thanh Cong"); 
		return NULL ;
	} a->data = x ; 
	  a->link = NULL ;
	  return a ; 
}

void ThemVaoDau( LIST &l , NODE *a){
	if( l.head == NULL){
		l.head = l.tail =a ;
	}else 
		a->link = l.head; 
		l.head = a; 
}

void ThemVaoCuoi( LIST &l , NODE *a){
	if( a == NULL){
		l.head = l.tail =a ;
	}else 
		l.head->link = a; 
		l.tail = a; 
}

void XuatDSLK( LIST l){
	printf("\Danh Sach Da Nhap Vao : "); 
		for(NODE *k = l.head; k != NULL ;k =k->link){
			printf("%d ",k->data); 
		}
}

// them vao 1 node vao sau Q trong danh sach lk
void ThemVaoTheoVitriQ(LIST &l ,NODE *p){
	int x ; 
	printf("\nNhap vao gia tri Q"); 
	scanf("%d",&x); 
	NODE *Q = KhoiTaoNode(x); 
	// neu nhu danh sach co 1 pt va cung chinh la Q => thanh bai toan them vao cuoi danh sach
	if( Q->data == l.head->data && l.head->link == NULL){
		ThemVaoCuoi(l,Q); 
	}else {
		
		// duyet tu dau cho den cuoi danh sach de tim node Q 
		for(NODE *k = l.head ; k != NULL ; k = k->link){
			// neu nhu Q ton tai thi cho P tro den NODE nam sau Q 
			if(Q->data == k->data){
				
			NODE *h = KhoiTaoNode(p->data);	// khoi tao NODE h moi them sau NODE Q
			NODE *g = k->link; // NODE g la trung gian
			h->link = g ; //B1: la moi lien ket tu h den g (g la NODE nam sau Q)
			k->link = h ; //B2: Tao moi lien ket tu NODE Q sang NDOE h
	
			}
		}
	}
}
void Menu(LIST &l){
	int luachon ; 
	while(true){
		printf("\n--------------MENU----------------");
		printf("\n\t1.Them Phan Tu"); 
		printf("\n\t2.Xuat Danh Sach");
		printf("\n\t3.Them NODE vao Sau NODE Q");
		printf("\n\t4.Thoat");  
		printf("\n--------------END-----------------"); 
	
		printf("\nLua chon "); 
		scanf("%d",&luachon); 
	
		if(luachon == 1){
			int x ; 
			printf("\nNhap vao so nguyen ");
			scanf("%d",&x); 
			NODE *a = KhoiTaoNode(x); 
			ThemVaoDau(l,a); 
			
		}else if(luachon == 2){
			XuatDSLK(l) ;
			getchar() ; //  getchar lenh tam dung chuong trinh
		
		}else if(luachon ==3){
			int x ; 
			printf("\nNhap gia tri can them");
			scanf("%d",&x); 
			NODE *p = KhoiTaoNode(x);
			// them node p vao sau node Q trong danh sach 
			ThemVaoTheoVitriQ(l,p); 
		}
		else{
			break ; // thoat ra
		}
	}	
}
int main (){
	LIST l ;
	KhoiTao(l) ;
	Menu(l); 
}






