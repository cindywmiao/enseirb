@str = constant[7 x i8] c"=> %d\0A\00"
define i32 @printf(i8*, ...){}
define i32 @calcule(i32 %x){
       %y = mul i32 %x ,%x
       %z = sub i32 %y , 10
       ret i32 %z
}
define i32 @calculelast(i32 %x){
       %y = mul i32 %x , %x
       %z = urem i32 %y ,10
       ret i32 %z
}

define i32 @main(){
       %x = call i32 @calcule(i32 32)
       call i32(i8*, ...)* @printf(i8 *getelementptr ([ 7 x i8] * @str, i32 0, i32 0), i32 %x)
       ret i32 0
}