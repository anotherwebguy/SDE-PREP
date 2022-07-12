int find(int A[],int X)
{
       //add code here
       if(X==A[X]) return X;
       return A[X]=find(A,A[X]);
}

void unionSet(int A[],int X,int Z)
{
	//add code here.
	int u = find(A,X);
	int v = find(A,Z);
	A[u]=v;
}

//O(4)-time
//O(N)-space
