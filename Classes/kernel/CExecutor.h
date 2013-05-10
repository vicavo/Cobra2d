#ifndef _CGEXECUTOR_H
#define _CGEXECUTOR_H


// Executor.h: interface for the Executor class.
//
//////////////////////////////////////////////////////////////////////
/*
	执行器类
	用于执行对象内声明为void* RemoteCall fun(void*)的成员函数
	※fun不能是虚函数
    使用方法
	class A
	{
		...
		void* RemoteCall fun(void*);
	}
	A a;
	//linux下必须&A::fun，windows下可使用A::fun，A类函数内部直接fun皆可
	//为了移植性，建议传递&A::fun给Bind()
	mdk::Executor::CallMethod( mdk::Executor::Bind(&A::fun), &a, (void*)param );
 */
#ifndef NULL
#define NULL 0
#endif

#ifndef WIN32
#define __stdcall 
#endif
#define RemoteCall __stdcall

typedef void* (*pfun)(void*);
typedef pfun FuntionPointer;
typedef unsigned __int64 MethodPointer;

class CExecutor  
{
public:
	CExecutor();
	virtual ~CExecutor();
	//成员函数指针地址
	//※f不能是虚函数
	template <typename FromType>
	static MethodPointer Bind( FromType f )
	{
		union 
		{
			FromType _f;
			MethodPointer  _t;
		}ut;
		
		ut._f = f;
		return ut._t;
	}
	//执行声明为void* fun(void*)的成员函数
	static void* CallMethod( MethodPointer method, void *pObj, void *pParam );
};

#endif // _CGEXECUTOR_H
