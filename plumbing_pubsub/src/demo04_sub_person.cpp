#include"ros/ros.h"
#include"plumbing_pubsub/Person.h"
void doPer(const plumbing_pubsub::Person::ConstPtr &person)
{
ROS_INFO("订阅的消息：%s,%d,%.2f",person->name.c_str(),person->age,person->height);
}
int main(int argc, char *argv[])
{
setlocale(LC_ALL,"");
//1节点初始化
ROS_INFO("这是订阅方");
ros::init(argc,argv,"jieshou");
//2创建句柄
ros::NodeHandle ns;
//3创建订阅者对象
ros::Subscriber sub=ns.subscribe("liaotian",10,doPer);
ros::spin();
    return 0;
}
