#include<iostream>
#include<string>
using namespace std;
int main(){
	char n[3];
	int j = 0;
	int cnt = 0;
	int position;
    string sentence1,sentence2;
	while(cnt<2){
		cin>>sentence1>>sentence2;
		for(int i=0;i<sentence1.length();i++){
			if(sentence1[i]==sentence2[i]&&sentence1[i]>'9'){
				n[j] = sentence1[i];
				position = i;
				j++;
			}
		}
		cnt++;
	}
	switch(n[0]){
        case 'a':    
		case 'A':cout<<"MON ";
			break;
        case 'b':
        case 'B':cout<<"TUE ";
		    break;
        case 'c':
        case 'C':cout<<"WEN ";
		    break;
        case 'd':
        case 'D':cout<<"THU ";
		    break;
        case 'e':
        case 'E':cout<<"FRI ";
		    break;
        case 'f':
        case 'F':cout<<"SAT ";
		    break;
        case 'g':
        case 'G':cout<<"SUN ";
		    break;
		default:
			break;    		
	}
	cout<<n[1]-55<<":";
	printf("%02d",position);
    return 0;
}