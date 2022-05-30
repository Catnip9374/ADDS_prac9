#include<vector>
#include<string>
#include<iostream>

using namespace std;



int main(int argc,char *argv[]) {
	vector<char> flag;
	vector<string> param;
	vector<int> number;
	string ans="";//结果算式 
	int res;//结果 
	int pre_priority=0; 
	for(int i=1;i<argc;++i){
		
		param.push_back(string(argv[i]));		
	}

	if(param.size()==1){
		//只有一个数字或符号
		cout<<"Error";
		return 0;
	} 
	for(int i=0;i<param.size();++i){
		if(param[i]=="*"||param[i]=="/"||param[i]=="+"||param[i]=="-"){
			//如果是符号就进栈 
			flag.push_back(param[i][0]);

		}else{
			//如果是数字
			if(number.size()==1){
				//如果数字栈中还有一个数字,弹出这个数字，计算值 
				int front=number.back();
				number.pop_back();
				//取出运算符
				if(flag.size()<1){
					//没有运算符号，那就出错了
						cout<<"Error";
						return 0;
					 
				}else{
					//构造运算值和最终的表达式 
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
						res=front/ stoi(param[i]);
						
						number.push_back(res);
				
						if(pre_priority==1){
							ans.insert(ans.begin(),1,'(');
							ans+=")";
						}
						pre_priority=2;
						ans=ans+"/"+param[i];
					}else{
						//出错 
						cout<<"Error";
						return 0;
					} 
				} 
				
			}else if(number.size()==0){
				//如果数字栈中没有数字
				 number.push_back(stoi(param[i])); 
				ans+=param[i];
			
			}else{
				//其他情况就出错了 
				cout<<"Error";
				return 0;
			}
			 
		}
		
	}
	
	//如果结束后数字栈不为1或者符号栈不为空，则结果出错
	if(flag.size()!=0||number.size()!=1){
		cout<<"Error";
		return 0;
	} 
	 
	cout<<ans<<"="<<res;
	return 0;
}
