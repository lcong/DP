/*
 * Adaptor.h
 *
 *  Created on: Aug 26, 2014
 *      Author: lcong
 */

#ifndef _ADAPTER_H_
#define _ADAPTER_H_

//目标接口类，客户需要的接口
class Target
{
public:
	Target();
	virtual ~Target();
	virtual void Request()=0; //定义标准接口
protected:

private:

};

//需要适配的类
class Adaptee
{
public:
	Adaptee();
	~Adaptee();
	void SpecificRequest();
};

//类模式，适配器类，通过public继承获得接口继承Request的效果，通过private继承获得实现继承SpecificRequest的效果
class Adapter0: public Target, private Adaptee
{
public:
	Adapter0();
	~Adapter0();
	virtual void Request(); //实现Target定义的Request接口
};

//对象模式，适配器类，继承Target类，采用组合的方式实现Adaptee的复用
class Adapter1: public Target
{
public:
	Adapter1(Adaptee* adaptee);
	Adapter1();
	~Adapter1();
	virtual void Request(); //实现Target定义的Request接口
private:
	Adaptee* _adaptee;
};

#endif /* ADAPTOR_H_ */
