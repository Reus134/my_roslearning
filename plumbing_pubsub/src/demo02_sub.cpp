#include"ros/ros.h"
#include"std_msgs/String.h"
//   发布方实现：
//     1，包含头文件
//     2.初始化ROS的节点
//     3.创建节点的句柄
//     4.创建订阅者者对象
//     5.处理订阅的数据
void doMsg(const std_msgs::String::ConstPtr &msg)//COnstPtr是常量指针的引用
{//通过msg获取并操作订阅到的数据
ROS_INFO("翠花订阅到的数据：%s",msg->data.c_str());//c_str是C类型的字符串

}
int main(int argc, char *argv[])
{//防止中文乱码
   setlocale(LC_ALL,"");
    //2.初始化ROS的节点
ros::init(argc,argv,"cuiHua");
//     3.创建节点的句柄
 ros::NodeHandle nh;
//     4.创建订阅者者对象    
ros::Subscriber sub=nh.subscribe("fang",10,doMsg);//doMsg回调函数处理订阅数据
   ros::spin();//回头
    return 0;
}
