#include <stdio.h>

// ---------- QUICK SORT ----------
void qs(int a[], int l, int h){
    if(l<h){
        int p=a[h],i=l-1;
        for(int j=l;j<h;j++)
            if(a[j]<=p){ i++; int t=a[i];a[i]=a[j];a[j]=t; }
        int t=a[i+1];a[i+1]=a[h];a[h]=t;
        int pi=i+1;
        qs(a,l,pi-1);
        qs(a,pi+1,h);
    }
}

// ---------- HEAP SORT ----------
void heapify(int a[], int n, int i){
    int l=2*i+1,r=2*i+2,largest=i;
    if(l<n && a[l]>a[largest]) largest=l;
    if(r<n && a[r]>a[largest]) largest=r;
    if(largest!=i){
        int t=a[i];a[i]=a[largest];a[largest]=t;
        heapify(a,n,largest);
    }
}

void hs(int a[], int n){
    for(int i=n/2-1;i>=0;i--) 
        heapify(a,n,i);
    for(int i=n-1;i>0;i--){
        int t=a[0];a[0]=a[i];a[i]=t;
        heapify(a,i,0);
    }
}

// ---------- MERGE SORT ----------
void merge(int a[], int l, int m, int r){
    int i=l,j=m+1,k=0,temp[50];
    while(i<=m && j<=r)
        temp[k++]=(a[i]<a[j])?a[i++]:a[j++];
    while(i<=m) temp[k++]=a[i++];
    while(j<=r) temp[k++]=a[j++];
    for(i=l,k=0;i<=r;i++,k++) a[i]=temp[k];
}

void ms(int a[], int l, int r){
    if(l<r){
        int m=(l+r)/2;
        ms(a,l,m);
        ms(a,m+1,r);
        merge(a,l,m,r);
    }
}

// ---------- MAIN ----------
int main(){
    int a[50],b[50],c[50],n;

    printf("Enter size: ");
    scanf("%d",&n);

    printf("Enter elements:\n");
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
        b[i]=c[i]=a[i];   // copy arrays
    }

    qs(a,0,n-1);
    hs(b,n);
    ms(c,0,n-1);

    printf("\nQuick Sort: ");
    for(int i=0;i<n;i++) 
        printf("%d ",a[i]);

    printf("\nHeap Sort: ");
    for(int i=0;i<n;i++) 
        printf("%d ",b[i]);

    printf("\nMerge Sort: ");
    for(int i=0;i<n;i++) 
        printf("%d ",c[i]);

    return 0;
}


// Enter size: 6
// Enter elements:
// 10 7 8 3 2 1

// Quick Sort: 1 2 3 7 8 10
// Heap Sort: 1 2 3 7 8 10
// Merge Sort: 1 2 3 7 8 10


