#include"ros/ros.h"
#include"std_msgs/String.h"
#include<sstream>
//   发布方实现：
//     1，包含头文件
//     2.初始化ROS的节点
//     3.创建节点的句柄
//     4.创建发布者对象

//     5.编写发布方数据
int main(int argc, char  *argv[])
{  //防止中文乱码
   setlocale(LC_ALL,"");
  //     2.初始化ROS的节点
   ros:: init(argc,argv,"erGouZi");
    //     3.创建节点的句柄
    ros:: NodeHandle nh;
    //     4.创建发布者对象
    ros::Publisher pub = nh.advertise<std_msgs::String>("fang",10);  //队列里面只有最新的10条
    //     5.编写发布方数据
    //要求以10HZ的频率发布数据，并且文本后添加编号
    //先创建被发布的消息
 std_msgs::String  msg;
 
 //发布频率
 ros::Rate rate(10);//10HZ发布数据
    //编写循环，循环中发布数据
    int count=0;
    while(ros::ok())//如果节点还活着 循环就继续发布
    {
      count++;
      //msg.data="hello";//msg要定义一下
      std::stringstream ss;
      ss<<"hello --->"<<count;//用流来实现字符串的拼接 
      msg.data=ss.str();//流里面的数据提取为字符串
      pub.publish(msg);
      //添加日志；
      ROS_INFO("发布的数据是:%s",ss.str().c_str());
      rate.sleep(); 
      ros::spinOnce();//回头处理回调函数一次；但是这个例子没有回调函数
    }
    
    return 0;
}

