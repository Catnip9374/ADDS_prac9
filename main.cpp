#include<vector>
#include<string>
#include<iostream>

using namespace std;



int main(int argc,char *argv[]) {
	vector<char> flag;
	vector<string> param;
	vector<int> number;
	string ans="";
	int res;
	int pre_priority=0; 
	 string tmp;
	while(cin>>tmp){
		param.push_back(tmp);
		if(cin.get()=='\n')break;
					
	}
	
	if(param.size()==1){
		cout<<"Error";
		return 0;
	} 
	for(int i=0;i<param.size();++i){
		if(param[i]=="*"||param[i]=="/"||param[i]=="+"||param[i]=="-"){
		
			flag.push_back(param[i][0]);

		}else{
			for(int j=0;j<param[i].length();++j){
				if(param[i][j]>'9'||param[i][j]<'0'){
					cout<<"Error";
					return 0;
				}
			} 
		
			if(number.size()==1){
			
				int front=number.back();
				number.pop_back();
		
				if(flag.size()<1){
				
						cout<<"Error";
						return 0;
					 
				}else{
					
					char c=flag.back();
					flag.pop_back();
					if(c=='+'){
						res= front+stoi(param[i]);
						
						number.push_back(res);
						pre_priority=1;
						ans=ans+"+"+param[i];
					}else if(c=='-'){
						
						res= front-stoi(param[i]);
						number.push_back(res);
						pre_priority=1;
						ans=ans+"-"+param[i];
					}else if(c=='*'){
						res= front*stoi(param[i]);
						number.push_back(res);
						if(pre_priority==1){
							ans.insert(ans.begin(),1,'(');
							ans+=")";
							
						}
						pre_priority=2;
						ans=ans+"*"+param[i];
					}else if(c=='/'){
						if(stoi(param[i])==0){
							cout<<"Error";
							return 0;
						}
						res=front/ stoi(param[i]);
						
						number.push_back(res);
				
						if(pre_priority==1){
							ans.insert(ans.begin(),1,'(');
							ans+=")";
						}
						pre_priority=2;
						ans=ans+"/"+param[i];
					}else{
					
						cout<<"Error";
						return 0;
					} 
				} 
				
			}else if(number.size()==0){
			
				number.push_back(stoi(param[i])); 
				ans+=param[i];
			
			}else{
				
				cout<<"Error";
				return 0;
			}
			 
		}
		
	}
	
	
	if(flag.size()!=0||number.size()!=1){
		cout<<"Error";
		return 0;
	} 
	 
	cout<<ans<<"="<<res;
	return 0;
}
