
void printSpiral(int mat[10][10],int n,int m){
		int start_col=0,end_col=m-1,start_row=0,end_row=n-1;

	while(start_col<end_col && start_row<end_row)
	{
		for(int i=start_row;i<=end_row;i++){
			cout<<mat[i][start_col]<<", ";
		}

		for(int i=start_col+1;i<=end_col;i++){
			cout<<mat[end_row][i]<<", ";
		}

		for(int i=end_row-1;i>=start_row;i--){
			cout<<mat[i][end_col]<<", ";
		}

		for(int i=end_col-1;i>start_col;i--){
			cout<<mat[start_row][i]<<", ";
		}

		start_col++;
		end_row--;
		end_col--;
		start_row++;
	}

	if(m>=n){//rows exhaust first
		if(start_row==end_row)//if they have crossed each other ,that means they have been already printed
		for(int i=start_col;i<=end_col;i++){
			cout<<mat[start_row][i]<<", ";
		}
	}	
	else{ //(n>m) columns exhaust first
		if(start_col==end_col)//if they have crossed each other ,that means they have been already printed
		for(int i=start_row;i<=end_row;i++){
			cout<<mat[i][start_col]<<", ";
		}
	}
	cout<<"END";
}
