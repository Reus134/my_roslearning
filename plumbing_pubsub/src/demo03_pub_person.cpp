#include"ros/ros.h"
#include"plumbing_pubsub/Person.h"
//发布人的消息
int main(int argc, char *argv[])
{
    setlocale(LC_ALL,"");
    //1节点初始化
ROS_INFO("这是发布方");
ros:: init(argc,argv,"banZhuRen");
//2创建句柄
ros:: NodeHandle n;
//3创建发布者
ros::Publisher pub = n.advertise<plumbing_pubsub::Person>("liaotian",10);
//4编写发布方的数据
//创建被发布的数据
plumbing_pubsub:: Person person;
person.name   = "张三";
person.age    = 1;
person.height = 1.73;
ros:: Rate rate(1);
while(ros::ok())
{person.age+=1;
    //核心：：发布数据
    pub.publish(person);
    ROS_INFO("发布的消息：%s,%d,%.2f",
              person.name.c_str(),person.age,person.height);
    rate.sleep();
    //建议
    ros::spinOnce();
}
    return 0;
}
