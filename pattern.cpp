#include<iostream>
using namespace std;

int main(){
 
int n=6;
// cout<<"Enter"<<endl;
// cin>>n;

// solid square
for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){
        cout<<"* ";
    }
    cout<<endl;
}
cout<<endl;

// hollow square pattern
for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){
        if(j==0 || j==n-1 || i==0 || i==n-1)
        cout<<"* ";
        else
        cout<<"  ";
    }
    cout<<endl;
}
cout<<endl;

// hollow inverted half pyramid

for(int i=0;i<n;i++){
    for(int j=0;j<n-i;j++){
        if(j==0 || i==0 || j==n-i-1)
        cout<<"* ";
        else 
        cout<<"  ";
    }
    cout<<endl;
}
cout<<endl;

// hollow full pyramid 
for(int i=0;i<n;i++){
    for(int j=0;j<n-i;j++){
        cout<<"  ";
    }
    for(int j=0;j<2*i + 1 ; j++){
        if(j==0 || j==2*i || i == n-1)
        cout<<"* ";
        else
        cout<<"  ";
    }
    cout<<endl;
}
cout<<endl;

// Numeric hollow pyramid 
for(int i=0;i<n;i++){
    for(int j=0;j<i+1;j++){
        if(j==0 || i==n-1 || j==i)
        cout<<j+1<<" ";
        else 
        cout<<"  ";
    }
    cout<<endl;
}
cout<<endl;

// Numeric hollow inverted 
for(int i=0;i<n;i++){
    for(int j=0;j<n-i;j++){
        if(j==0 || i==0 || j==n-i-1)
        cout<<j+1<<" ";
        else 
        cout<<"  ";
    }
    cout<<endl;
}
cout<<endl;

//Numeric pallindromew equilateral pyramid
for(int i=0;i<n;i++){
    for(int j=0;j<n-i;j++){
        cout<<"  ";
    }
    for(int j=0;j<2*i + 1 ; j++){
        if(j<i+1)
        cout<<j+1<<" ";
        else
        cout<<2*i-j+1<<" ";
      
    }
    cout<<endl;
}
cout<<endl;

// solid half pyramid 

for(int i=0;i<n;i++){
    for(int j=0;j<i;j++){
        cout<<"* ";
    }
    cout<<endl;
}

for(int i=0;i<n;i++){
    for(int j=0;j<n-i;j++){
        cout<<"* ";
    }
    cout<<endl;
}
cout<<endl;

// fancy pattern 1;
for(int i=0;i<n;i++){
    for(int j=0;j<8-i-1;j++){
        cout<<"* ";
    }
    for(int j=0;j<2*i+1;j++){
        if(j % 2== 0)
        cout<<i+1<<" ";
        else
        cout<<"* ";
    }
    for(int j=0;j<8-i-1;j++){
        cout<<"* ";
    }

    cout<<endl;
}
cout<<endl;

// Fancy patern 2
int c =1;

for(int i=0;i<n;i++){
    for(int j=0;j<(2*i+1);j++){
        if(j%2 == 0)
        cout<<c++<<" ";
        else
        cout<<"* ";
    }
    cout<<endl;
}

c -= 6;
for(int i=0;i<n;i++){
    for(int j=0;j<(2*n+1)-(2*i + 1)-1;j++){
        if(j%2 == 0)
        cout<<c++<<" ";
        else
        cout<<"* ";
    }
    c -= n ;
    c += i;
    c -= (n-i);
    c++;
    cout<<endl;
}
cout<<endl;

// fancy pattern 3 
for(int i=0;i<n;i++){
    for(int j=0;j<2*i+1;j++){
        if(j==0 || j==2*i)
        cout<<"* ";
        else if(j<=i)
        cout<<j<<" ";
        else
        cout<<2*i -j<<" ";
    }
    cout<<endl;
}

for(int i=0;i<n;i++){
    for(int j=0;j<2*n-2*i+1;j++){
        if(j==0 || j== 2*n-2*i)
        cout<<"* ";
        else if(j<=(2*n-2*i)/2)
        cout<<j<<" ";
        else
        cout<<2*n-2*i -j<<" ";
    }
    cout<<endl;
}
cout<<endl;










return 0;
}