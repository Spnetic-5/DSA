#include <ros/ros.h>
#include <eigen3/Eigen/Dense>
#include <visualization_msgs/Marker.h>
#include <cmath>


double substitute_point_in_line(const Eigen::Vector2d &pt1,
                                const Eigen::Vector2d &pt2,
                                const Eigen::Vector2d &query_point) {
    return ((query_point.y() - pt1.y()) * (pt2.x() - pt1.x())) -
           ((query_point.x() - pt1.x()) * (pt2.y() - pt1.y()));
};

void is_point_inside_convex_polygon(const Eigen::Vector2d &query_point,
   std::vector<Eigen::Vector2d> &vertices){
    int wn = 0;  // the  winding number counter
    const int num_sides_of_polygon = vertices.size();

    for (size_t i = 0; i < num_sides_of_polygon; ++i) {
        const auto point_in_line = substitute_point_in_line(
            vertices[i], vertices[(i + 1) % num_sides_of_polygon], query_point);

        // Check if the point lies on the polygon.
       
        if (vertices[i].y() <= query_point.y()) {
            // Upward crossing.
            if (vertices[(i + 1) % num_sides_of_polygon].y() >
                query_point.y()) {
                if (point_in_line > 0) {
                    ++wn;  // query point is left of edge
                }
            }
        } else {
            // Downward crossing.
            if (vertices[(i + 1) % num_sides_of_polygon].y() <
                query_point.y()) {
                if (point_in_line < 0) {
                    --wn;  // query point is right of edge
                }
            }
        }
    }
    int point;
    if(point != 0){
        int point = 0;
    }
    
    if(wn != 0){
        std::cout<<query_point.x()<<","<<query_point.y()<<" "<<"Inside"<<std::endl;
        point++;
    }
    else{
        std::cout<<query_point.x()<<","<<query_point.y()<<" "<<"Outside"<<std::endl;
    }

    std::cout<<"-------------------"<<std::endl;
    
}

int main( int argc, char** argv )
{
  ros::init(argc, argv, "points_and_lines");
  ros::NodeHandle n;
  ros::Publisher marker_pub = n.advertise<visualization_msgs::Marker>("visualization_marker", 10);

  ros::Rate r(30);

  float f = 0.0;
  
     while (ros::ok())
      {
    visualization_msgs::Marker points, polygon;
    points.header.frame_id = polygon.header.frame_id = "map";
    points.header.stamp = polygon.header.stamp = ros::Time::now();
    points.ns = polygon.ns = "points_and_lines";
    points.action = polygon.action = visualization_msgs::Marker::ADD;
    points.pose.orientation.w = polygon.pose.orientation.w = 1.0;

    points.id = 0;
    polygon.id = 1;

    points.type = visualization_msgs::Marker::POINTS;
    polygon.type = visualization_msgs::Marker::LINE_STRIP;

    // POINTS markers use x and y scale for width/height respectively
    points.scale.x = 0.01;
    points.scale.y = 0.01;

    // LINE_STRIP/LINE_LIST markers use only the x component of scale, for the line width
    polygon.scale.x = 0.01;

    // Points are green
    points.color.g = 1.0f;
    points.color.a = 1.0;

    // Line strip is blue
    polygon.color.b = 1.0;
    polygon.color.a = 1.0;

    // Create the vertices for the points and lines
    std::vector<Eigen::Vector2d> vertices{{0, 0.5}, {0.5, 0}, {0.5, -0.5},  {0, 0}, {-0.5, 0}, {0.5, -0.5}, {0, 0.5}};
    std::vector<Eigen::Vector2d> query_points{
        {0.0, 0.0}, {0.7, 0.7}, {0.5, 0.2}, {-0.3, 0.4}, {0.2, 0.1}, {0, 0.5}, {0.9, 0.3}, {0.2, -0.7},  {-0.12, -0.52}, {-0.8, 0}, {0.3, -0.4}};
    // , {0.3, 0.1}, {0.0, 0.0}, {0.7, 0.9}
    // outside pt 

    // Test pts 
     for (size_t j = 0; j < query_points.size(); ++j){
        geometry_msgs::Point pt;
        pt.x = query_points[j][0];
        pt.y = query_points[j][1];
        pt.z = 0.;
        points.points.push_back(pt);
    }
    
    // polygon pts 
    for (size_t j = 0; j < vertices.size(); ++j){
        geometry_msgs::Point v;
        v.x = vertices[j][0];
        v.y = vertices[j][1];
        v.z = 0.;
        polygon.points.push_back(v);
    }

    
    marker_pub.publish(points);
    marker_pub.publish(polygon);
    
    for (const auto &point : query_points) {
        is_point_inside_convex_polygon(point, vertices);
    }
    std::cout<<"-----------         REPEAT                 --------"<<std::endl;
    r.sleep();

    f += 0.04;
      }
}

