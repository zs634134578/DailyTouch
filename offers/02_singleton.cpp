/*
 * Singleton 单例模式的实现
 *
 * 1 什么是单例模式
 *
 *     保证一个类仅有一个实例，并提供一个访问它的全局访问点
 *
 * 2 单例模式的应用场景
 *
 *     类只能有一个实例，并且客户可以从一个众所周知的访问点访问它时。
 *
 * 3 实现细节
 *     
 *     1 访问点必须为static，唯一的实例也必须为static
 *     2 构造函数必须为private或者protected
 *     3 加锁前后两次判断对象是否是NULL，提高多线程场景的效率
 *     4 C++中，常用的锁的用法
 *     5 类的静态成员变量在使用前必须初始化
 *
 */


#include <iostream>
#include <pthread.h>

class Moon
{
public:
	static Moon* Instance();
	void SayHello();

protected:
	Moon();
	virtual ~Moon() {};

private:
	static pthread_mutex_t mMutex;
	static Moon* mMoon;
};

Moon* Moon::mMoon = NULL;
pthread_mutex_t Moon::mMutex;

Moon* Moon::Instance()
{
	if (mMoon == NULL)
	{
		pthread_mutex_lock(&mMutex);
		if (mMoon == NULL)
		{
			mMoon = new Moon();
		}
		pthread_mutex_unlock(&mMutex);
	}

	return mMoon;
}

Moon::Moon()
{
	std::cout << "Constructor Called" << std::endl;
}

void Moon::SayHello()
{
	std::cout << "Hello Earth" << std::endl;
}

int main()
{
	Moon* moonA = Moon::Instance();
	moonA->SayHello();
	Moon* moonB = Moon::Instance();
	moonB->SayHello();
	return 0;
}
