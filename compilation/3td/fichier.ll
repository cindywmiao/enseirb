define i32 @mafonction(i32 %arg) {    
   %x = mul i32 %arg, 2  
   %y = add i32 %x , 32  
   %z = sub i32 %y , %x  
   %a = sdiv i32 %z, 4   
   ret i32 %a
}
define i32 @main() {    
   %retval = call i32 @mafonction(i32 42)
   ret i32 0
}
