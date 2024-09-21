#include<stdio.h>
struct node{
	int data ; 
	struct node *pNext ; //  lieen keet giua cac node 
	
};
typedef struct node NODE; // thay the struct node thanh NODE
// khai bao cau truc cua danh sach lien ket don
struct list{
	NODE *phead; // con tro node dau
	NODE *ptail;  // con tro node cuoi
	
};
// thay the struct list thanh LIST
typedef struct list LIST; 
// khoi tao danh sach lk

void Khoitao(LIST &l){
	l.phead = NULL ;
	l.ptail = NULL; 
	// cho 2 node tro den NULL  vi danh sach chuaw cos phaan tu
	
}
// ham khoi tao node 
// x la kieu nguyen de truyen du lieu so nguyen vao danh sach

NODE *KhoiTaoNODE(int x){
	NODE *a = new NODE ; // cap phat vung nho cho NODE p
	if( a == NULL){
		printf("Khong du bo nho phat");
		return NULL; 
	}
	a->data = x ; // gia tri x ngoai vao data
	a->pNext = NULL ; // dau tien moi khai bao thi no chuaw cos node nao nen tro den NULL 
	return a ; // tra ve node p vua khoi tao
}

// Ham them node vao dau danh sach
void ThemVaoDau(LIST &l, NODE *a){
	// danh sach dang rong
	if(l.phead == NULL){
		l.phead = l.ptail = a; // rong thi node dau hay cuoi cung nhu nhau	
	}else{
		a->pNext= l.phead ;  // cho con tro cua node cân them la node a lien ket voi node dau phead
		l.phead = a; // cap nhap lai node dau a
	}

}
// Them node p vao cuoi danh sach lien ke
void ThemVaCuoi(LIST &l, NODE *a){
	// danh sach dang rong
	if(l.phead == NULL){
		l.phead = l.ptail = a; // rong thi node dau hay cuoi cung nhu nhau	
	}else{
		l.ptail->pNext; // con tro cua ptail lien ket vs ndoe a
		l.ptail = a; // cap nhat lai
	}
}

void XuatDanhSach(LIST l){
	// for( int i = 0 ; i<n ;i++)
	for(NODE *k = l.phead ; k !=NULL;k = k->pNext)
	{
		printf("%d  ",k->data); // dung tro k de tro den du lieu data
	}
}

int TimMax(LIST l){
	int max = l.phead->data; // cho max la gtri dau tien nhu a[0]
	// tiep vong for cho k bat dau tu vi tri ke tiep nhu a[1]
	for( NODE *k = l.phead->pNext; k != NULL; k = k->pNext){
		if(max < k->data){
			max= k->data  ;
		}
	} 
	return max; 
}

int main(){
	LIST l ;
	Khoitao(l) ; // khoi tao danh sach lien ket don
	int n; printf("\nNhap sl node can them ");
	scanf("%d",&n);
	for(int i =1; i<= n; i++)
		{
			int x ; 
			printf("\nNhap gt so nguyen : "); 
			scanf("%d",&x);	
			NODE *a = KhoiTaoNODE(x); // hkoi tao 1 cai node so nguyen
			ThemVaoDau(l,a);
		}
	printf("\n Danh Sach Lien Ket Don: "); 
	XuatDanhSach(l); 
	printf("\nGia tri lon nhat cua MAX : %d ",TimMax(l)); 
}
