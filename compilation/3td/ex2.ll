@str = constant[7 x i8] c"=> %d\0A\00"
define i32 @printf(i8*, ...){}
define i32 @calcule(i32 %x){
       %a = alloca i32
       %y = alloca i32
       %z = alloca i32
       
       %t1 = mul i32 %x,3
       store i32 %t1, i32* %a
       
       %t2 = load i32* %a
       %t3 = add i32 %t2,5
       store i32 %t3, i32* %y
       
       %t4 = load i32* %a
       %t5 = load i32* %y
       %t6 = mul i32 %t4,%t5
       store i32 %t6, i32* %z
       
       %val = load i32* %z
       ret i32 %val 
}

define i32 @main(){
       %x = call i32 @calcule(i32 32)
       call i32(i8*, ...)* @printf(i8 *getelementptr ([ 7 x i8] * @str, i32 0, i32 0), i32 %x)
       ret i32 0
}