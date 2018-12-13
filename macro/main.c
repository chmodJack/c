
#pragma message("Show this message.")

#error Please delete me

__attribute__((optimize("O0")))
int add1(int a,int b)
{
	return a+b;
}

__attribute__((optimize("Ofast")))
int add2(int a,int b)
{
	return a+b;
}

__attribute__((optimize("O2")))
int add3(int a,int b)
{
	return a+b;
}

//目前还想不出来这个的高级用法
#define MACRO_ARGS(x,y,...) FUNC(#__VA_ARGS__,x,y)

//宏定义压栈出栈，优化选项也可以像这样压栈出栈
//例如不知道头文件哪里是否定义了MACRO宏，可以这样做，既不会损坏之前的宏定义，又能自己再定义新的

//此处可以模拟是否在头文件某个地方使用了宏定义
#define MACRO int fuck

#ifdef MACRO
#pragma push_macro("MACRO")
#else
//此处要这样定义一些，要不然两种情况下出入栈情况不一样，会导致一些问题
#define MACRO /**/
#pragma push_macro("MACRO")
#endif

#define MACRO int first
//此处会展开为first
MACRO;
//把定义的first压栈
#pragma push_macro("MACRO")
//可以再重新定义
#define MACRO int second
//此处展开为second
MACRO;
//宏定义出栈
#pragma pop_macro("MACRO")
//此处会展开为first
MACRO;
//再出栈
#pragma pop_macro("MACRO")
//若之前定义过MACRO，则会展开为之前的，否则展开为/**/
MACRO;
