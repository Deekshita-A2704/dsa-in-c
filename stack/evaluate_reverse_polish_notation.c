int evalRPN(char** tokens, int tokensSize) {
    int st[10000],top = -1;

    for(int i = 0; i< tokensSize; i++){
        if(strlen(tokens[i]) == 1 && strchr("+-*/",tokens[i][0])) {
            int b = st[top--];
            int a = st[top--];

            switch(tokens[i][0]){
                case '+':st[++top] = a + b; break;
                case '-':st[++top] = a - b; break;
                case '*':st[++top] = a * b; break;
                case '/':st[++top] = a / b; break;
            }
        }
        else {
            st[++top] = atoi(tokens[i]);

        }
    }
    return st[top];
}
