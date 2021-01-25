using namespace std;
int count;
void nQueens(int placed[],int cols[],int n,int i){
   // cout<<"called for i= "<<i<<endl;
    if (i>n) {
        count++;
        cout<<"[";
        for (int c=1;c<=n;c++) cout<<placed[c]<<" ";
        cout<<"] ";
        return ;
    }
    
    
    for (int j=1;j<=n;j++){
        if (i==1){
        // cout<<"### i=1 "<<endl;
           // cout<<"Placed at "<<j<<endl;
            placed[1] = j;
            cols[j] = j;
            nQueens(placed,cols,n,i+1);
            cols[j] = 0;
            placed[1] = 0;
        }else {
          // cout<<"checking to put queen no "<<i<<" at column "<<j<<endl;
            if (cols[j]==0) //check threat from above 
            {   int flagL=0,flagR=0;
               // check threat from diagonal
                // diagonally left
                int ti,tj;
                for (ti = i-1 ,tj = j-1 ;ti>=1 && tj >=1;ti--,tj--){
                    if (placed[ti]==tj) {
                        flagL=1;
                        break;
                    }
                }
                if (flagL==0){
                    for ( ti = i-1 , tj = j+1 ;ti>=1 && tj <=n;ti--,tj++){
                    if (placed[ti]==tj) {
                        flagR=1;
                        break;
                    }
                }
                
                if (flagL==0 && flagR==0){
                 //   cout<<"Placed at "<<j<<"queen no "<<i<<endl;
                    placed[i] = j;
                    cols[j] = 1;
                    nQueens(placed,cols,n,i+1);
                    cols[j] = 0;
                    placed[i] = 0;
                }
               // else cout<<"queen has threat from digonal right "<<endl;
                
                } 
               // else cout<<"queen has threat from digonal left"<<endl;
            }
          // else cout<<"queen has threat from above"<<endl;
            
            
        }
    }
}
int main()
 {int t;
 cin>>t;
  while (t--){
      int n;
      cin>>n;
      int a[n+1] = {0};
      int b[n+1] = {0};
      count=0;
      nQueens(a,b,n,1);
      if (count==0) cout<<-1<<endl;
      else cout<<endl;
      
  }
	//code
	return 0;
}
