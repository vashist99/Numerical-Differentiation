//Vashist Hegde
//Indian Institute of Information Technology Vadodaras
#include<bits/stdc++.h>
#define lld long double
using namespace std;

vector<lld> forward(lld val,vector<lld> h ){
    vector<lld>t;

    vector<lld> cost;
    
    vector<lld> err;
    lld p;
   
    
    //calculation:
    for(int i=0;i<h.size();i++){
        t.clear();
        cost.clear();
        lld temp = 0;
        while(temp<=0.01){
            temp=temp+h[i];
            //cout<<temp<<"\n";
            
            t.push_back(temp);
        }

        for(int j=0;j<t.size();j++){
        cost.push_back(cos(t[j]));
    }

     lld del1y0 = cost[1] - cost[0];
     lld del2y0 = cost[2] - 2*cost[1] + cost[0];
     lld del3y0 = cost[3] - 3*cost[2] + 3*cost[1] - cost[0]; 

        p = (val - t[0])/(h[i]);
        lld calculated_derivative = (del1y0+((2*p-1)*del2y0/2)+((3*p*p-6*p+2)*del3y0/6))/(h[i]);
        lld error = abs(calculated_derivative + sinf64x(val));
        err.push_back(error);
    }
    
    return err;

}

vector<lld> central(lld val,vector<lld> h){
   // cout<<"ksjfks\n";
    vector<lld> t;
    vector<lld> cost;
    
    vector<lld> err;
    lld p;
    
    //cout<<"ha\n";
    //calculation:
    for(int i=0;i<h.size();i++){
        
        t.clear();
        cost.clear();
        lld temp = 0;
        while(temp<=0.01){
            temp=temp+h[i];
            //cout<<temp<<"\n";
            t.push_back(temp);
        }

        //cout<<"test1\n";

        for(int j=0;j<t.size();j++){
        cost.push_back(cos(t[j]));
    }
    
    lld del1y0 = cost[1] - cost[0];
    lld del2y0 = cost[2] - 2*cost[1] + cost[0];
    lld del3y0 = cost[3] - 3*cost[2] + 3*cost[1] - cost[0]; 


       
        p = (val - t[0])/h[i];
        lld calculated_derivative = (del1y0+((2*p-1)*del2y0/2)+((3*p*p-1)*del3y0/6))/h[i];
        lld error = abs(calculated_derivative + sinf64x(val));
        err.push_back(error);
    }
   // cout<<"test3\n";
    

    return err;
}

lld N(lld h,lld val,lld t0,lld t1,lld t2,vector<lld> cost){
    lld del1y0 = cost[1] - cost[0];
    lld del2y0 = cost[2] - 2*cost[1] + cost[0];
    lld del3y0 = cost[3] - 3*cost[2] + 3*cost[1] - cost[0];
    
    return cost[0] + ((val-t0)*del1y0/h) + ((val-t0)*(val-t1)*del2y0/(2*h*h)) + ((val-t0)*(val-t1)*(val-t2)*del3y0/(6*h*h*h));
}

vector<lld> extra(lld val,vector<lld> h){

    vector<lld> cost;
    vector<lld> t;
    
    vector<lld> err;
    lld p;
     
    
    //calculation:
    for(int i=0;i<h.size();i++){
         t.clear();
         cost.clear();
        lld temp = 0;
        while(temp<=0.01){
            temp=temp+h[i];
            //cout<<temp<<"\n";
            
            t.push_back(temp);
        }

        for(int j=0;j<t.size();j++){
        cost.push_back(cos(t[j]));
    }
        

        lld term1 = N(h[i],(val+(h[i]/4)),t[0],t[1],t[3],cost);
        lld term2 = N(h[i],(val-(h[i]/4)),t[0],t[1],t[3],cost);
        lld term3 = N(h[i],(val+(h[i]/2)),t[0],t[1],t[3],cost);
        lld term4 = N(h[i],(val-(h[i]/2)),t[0],t[1],t[3],cost);
    


        p = (val - t[0])/h[i];
        lld calculated_derivative = 8*(term1-term2-term3+term4)/(3*h[i]); 
        lld error = abs(calculated_derivative + sinf64x(val));
        err.push_back(error);
    }
    

    return err;

}


int main(){
    vector<lld> h;
    vector<lld> t;
    
    //to store the final answers:
    vector<lld> ef01;
    vector<lld> ef1;
    vector<lld> ef100;

    vector<lld> ec01;
    vector<lld> ec1;
    vector<lld> ec100;

    vector<lld> ee01;
    vector<lld> ee1;
    vector<lld> ee100;

    //h.push_back(1);
    t.push_back(0);
    double H = 0.00001;
    int count=0;
    long long int max;
    max = 1000000000000;

    
    // while(H>0){
    //     //lld temp = 0;
    //     //cout<<H<<"\n";
    //     H = H/max;
        
    //     h.push_back(H);
    //     count+=1;
    //     cout<<count<<"\n";
        
    //     //cout<<H<<"\n";
        
    // }

    h = {0.001,0.0015,0.0001,0.00015,0.00001,0.00001,0.0000015,0.0000001,0.00000015};

    //cout<<h.size()<<"\n";
    
cout<<"forward difference:\n";
    cout<<"h       "<<" "<<"error\n";
    cout<<"x = 0.1----------\n";
    ef01 = forward(0.1,h);
    for(int i=0;i<ef01.size();i++){
         cout<<h[i]<<" | "<<ef01[i]<<"\n";
     }
cout<<"x = 1----------\n";
    ef1 = forward(1,h);
    for(int i=0;i<ef1.size();i++){
         cout<<h[i]<<" | "<<ef1[i]<<"\n";
     }
cout<<"x = 100----------\n";
    ef100 =forward(100,h);
     for(int i=0;i<ef100.size();i++){
         cout<<h[i]<<" | "<<ef100[i]<<"\n";
     }

   cout<<"Central difference:\n";
   cout<<"h       "<<" "<<"error\n";
   cout<<"x = 0.1----------\n";
    ec01 = central(0.1,h);
    for(int i=0;i<ec01.size();i++){
         cout<<h[i]<<" | "<<ec01[i]<<"\n";
     }
     cout<<"x = 1----------\n";
    ec1 = central(1,h);
    for(int i=0;i<ec1.size();i++){
         cout<<h[i]<<" | "<<ec1[i]<<"\n";
     }
     cout<<"x = 100----------\n";
    ec100 = central(100,h);
    for(int i=0;i<ec100.size();i++){
         cout<<h[i]<<" | "<<ec100[i]<<"\n";
     }
    cout<<"extrapolated difference:\n";
    cout<<"h       "<<" "<<"error\n";
    cout<<"x = 0.1----------\n";
    ee01 = extra(0.1,h);
     for(int i=0;i<ee01.size();i++){
         cout<<h[i]<<" | "<<ee01[i]<<"\n";
     }
     cout<<"x = 1----------\n";
    ee1 = extra(1,h);
    for(int i=0;i<ee1.size();i++){
         cout<<h[i]<<" | "<<ee1[i]<<"\n";
     }
     cout<<"x = 100----------\n";
    ee100 = extra(100,h);
    for(int i=0;i<ee100.size();i++){
         cout<<h[i]<<" | "<<ee100[i]<<"\n";
     }
     cout<<"----------\n";

    /*for(int i=0;i<h.size();i++){
        cout<<h[i]<<"\n";
    }*/

}
