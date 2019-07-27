/*
*	Author: Douglas Dias da Silva
*	Date:	18/07/2019
*	Email: douglas.dias2102@outlook.com
*/

#include<stdlib.h>
#include<stdio.h>

char INPUT[100000000] = /*"S(S(S(KS)(S(KK)(SKK)))(K(S(SKK)(SKK))))(S(S(KS)(S(KK)(SKK)))(K(S(SKK)(SKK))))";*/ "SA(B2W)(CHJ)HJHJ";
char OUTPUT[100000000] = "";

int GetSubstringEnd(char in[], int end){
	int openParenthesis = 1;
	while(openParenthesis != '\0'){
		if(in[end] == '(')
			openParenthesis++;
		else if(in[end] == ')')
			openParenthesis--;
		end++;
	}
	return end;
}

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

void S(char in[], char out[]){
	if(in[1] != '('){
		if(in[2] != '('){
			if(in[3] != '('){
				out[0] = '(';
				out[1] = in[1];
				out[2] = in[3];
				out[3] = ')';
				out[4] = '(';
				out[5] = in[2];
				out[6] = in[3];
				out[7] = ')';
				
				int i, j = 8;
				for(i = 4; in[i] != '\0'; i++){
					out[j] = in[i];	
					j++;
				}
				out[j] = '\0';
			} else {
				int cStart = 3;
				int cEnd = GetSubstringEnd(in, cStart + 1);
				
				out[0] = '(';
				out[1] = in[1];
				
				int iteratorIn;
				int iteratorOut = 2;
				for(iteratorIn = cStart; iteratorIn < cEnd; iteratorIn++){
					out[iteratorOut] = in[iteratorIn];
					iteratorOut++;
				}
				
				out[iteratorOut] = ')';
				iteratorOut++;
				out[iteratorOut] = '(';
				iteratorOut++;
				out[iteratorOut] = in[2];
				iteratorOut++;
				
				for(iteratorIn = cStart; iteratorIn < cEnd; iteratorIn++){
					out[iteratorOut] = in[iteratorIn];
					iteratorOut++;
				}
				
				out[iteratorOut] = ')';
				iteratorOut++;
				
				for(iteratorIn = cEnd; in[iteratorIn] != '\0'; iteratorIn++){
					out[iteratorOut] = in[iteratorIn];	
					iteratorOut++;
				}
				
				out[iteratorOut] = '\0';
			}
		} else {
			int bStart = 2;
			int bEnd = GetSubstringEnd(in, bStart + 1);
			
			if(in[bEnd] != '('){
				out[0] = '(';
				out[1] = in[1];
				out[2] = in[bEnd];
				out[3] = ')';
				out[4] = '(';
				
				int inIterator, outIterator = 5;
				for(inIterator = bStart; inIterator < bEnd; inIterator++){
					out[outIterator] = in[inIterator];
					outIterator++;
				}
				
				out[outIterator] = in[bEnd];
				outIterator++;
				out[outIterator] = ')';
				outIterator++;
				
				for(inIterator = bEnd + 1; in[inIterator] != '\0'; inIterator++){
					out[outIterator] = in[inIterator];
					outIterator++;
				}
				out[outIterator] = '\0';
				
			} else {
				int cStart = bEnd;
				int cEnd = GetSubstringEnd(in, cStart + 1);
				
				out[0] = '(';
				out[1] = in[1];
				
				int inIterator, outIterator = 2;
				for(inIterator = cStart; inIterator < cEnd; inIterator++){
					out[outIterator] = in[inIterator];
					outIterator++;
				}
				
				out[outIterator] = ')';
				outIterator++;
				
				out[outIterator] = '(';
				outIterator++;
				
				for(inIterator = bStart; inIterator < bEnd; inIterator++){
					out[outIterator] = in[inIterator];
					outIterator++;
				}
				
				inIterator = cStart;
				for(inIterator = cStart; inIterator < cEnd; inIterator++){
					out[outIterator] = in[inIterator];
					outIterator++;
				}
				
				out[outIterator] = ')';
				outIterator++;
				
				for(inIterator = cEnd; in[inIterator] != '\0'; inIterator++){
					out[outIterator] = in[inIterator];
					outIterator++;
				}
				
				out[outIterator] = '\0';
			}
		}
	} else {
		
	}
}
void NextOperation(char in[], char out[]){
	switch(in[0]){
		case 'K':
			K(in, out);
			break;	
		case 'S':
			S(in, out);
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
