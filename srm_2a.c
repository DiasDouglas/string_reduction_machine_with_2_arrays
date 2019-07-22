/*
*	Author: Douglas Dias da Silva
*	Date:	18/07/2019
*	Email: douglas.dias2102@outlook.com
*/

#include<stdlib.h>
#include<stdio.h>

char INPUT[100000000] = /*"S(S(S(KS)(S(KK)(SKK)))(K(S(SKK)(SKK))))(S(S(KS)(S(KK)(SKK)))(K(S(SKK)(SKK))))";*/ "K(KU)(VK)LYTY";
char OUTPUT[100000000] = "";

void K(char in[], char out[]){
	if(in[1] != '('){
		int i = 2;
		out[0] = in[1];
		if(in[2] != '('){
			out[1] = in[3];
			while(in[i + 2] != '\0'){
				out[i] = in[i + 2];
				i++;
			}
			out[i] = '\0';
		} else {
			int outPointer = 1;
			int openParenthesis = 1;
			i++;
			while(openParenthesis != 0){
				switch(in[i]){
					case '(':
						openParenthesis++;
						break;
					case ')':
						openParenthesis--;
					default:
						break;
				}
				i++;
			}
			while(in[i] != '\0'){
				out[outPointer] = in[i];
				outPointer++;
				i++;
			}
			out[outPointer] = '\0';
		}
	} else {
		int openParenthesis = 1;
		int i = 2;
		int j = 0;
		
		while(openParenthesis != 0){
			if(in[i] == '(')
				openParenthesis++;
			else if(in[i] == ')')
				openParenthesis--;
			
			if(openParenthesis != 0){
				out[j] = in[i];
				j++;
			}
			i++;
		}
		
		if(in[i] != '('){
			while(in[i + 1] != '\0'){
				out[j] = in[i + 1];
				i++;
				j++;
			}
		} else {
			int openParenthesis = 1;
			i++;
			
			while(openParenthesis != 0){
				if(in[i] == '(')
					openParenthesis++;
				else if(in[i] == ')')
					openParenthesis--;
				
				i++;
			}
			
			while(in[i] != '\0'){
				out[j] = in[i];
				i++;
				j++;
			}
		}
	}
}

void NextOperation(char in[], char out[]){
	switch(in[0]){
		case 'K':
			K(in, out);
			break;	
		default:
			return;
	}
}

int main(){
	NextOperation(INPUT, OUTPUT);
	printf("%s", &OUTPUT);
	return 0;
}
