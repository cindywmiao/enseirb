void print_begin() {
        puts("@str = constant [ 7 x i8 ] c\"=> %d\\0A\\00\"");
        puts("declare i32 @printf(i8*, ...)\n");
        puts("define i32 @calcule() {");
}

void print_end() {
        puts("}\n");
        puts("define i32 @main() {");
        puts("\t%x = call i32 @calcule()");
        puts("\tcall i32 (i8*, ...)* @printf(i8* getelementptr ([7 x i8]* @str, i32 0, i32 0), i32 %x)");
        puts("\tret i32 0\n}");
}

int main(int argc, char **argv) {
        reg = 0;
        print_begin();
        yyparse();
        print_end();
        return 0;
} 
