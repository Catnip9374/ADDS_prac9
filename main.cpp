#include<vector>
#include<string>
#include<iostream>

using namespace std;



int main(int argc,char *argv[]) {
	vector<char> flag;
	vector<string> param;
	vector<int> number;
	string ans="";//�����ʽ 
	int res;//��� 
	int pre_priority=0; 
	for(int i=1;i<argc;++i){
		
		param.push_back(string(argv[i]));		
	}

	if(param.size()==1){
		//ֻ��һ�����ֻ����
		cout<<"Error";
		return 0;
	} 
	for(int i=0;i<param.size();++i){
		if(param[i]=="*"||param[i]=="/"||param[i]=="+"||param[i]=="-"){
			//����Ƿ��žͽ�ջ 
			flag.push_back(param[i][0]);

		}else{
			//���������
			if(number.size()==1){
				//�������ջ�л���һ������,����������֣�����ֵ 
				int front=number.back();
				number.pop_back();
				//ȡ�������
				if(flag.size()<1){
					//û��������ţ��Ǿͳ�����
						cout<<"Error";
						return 0;
					 
				}else{
					//��������ֵ�����յı��ʽ 
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
						//���� 
						cout<<"Error";
						return 0;
					} 
				} 
				
			}else if(number.size()==0){
				//�������ջ��û������
				 number.push_back(stoi(param[i])); 
				ans+=param[i];
			
			}else{
				//��������ͳ����� 
				cout<<"Error";
				return 0;
			}
			 
		}
		
	}
	
	//�������������ջ��Ϊ1���߷���ջ��Ϊ�գ���������
	if(flag.size()!=0||number.size()!=1){
		cout<<"Error";
		return 0;
	} 
	 
	cout<<ans<<"="<<res;
	return 0;
}
