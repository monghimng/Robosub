string convertInt(int number)
{
   stringstream ss;//create a stringstream
   ss << number;//add number to the stream
   return ss.str();//return a string with the contents of the stream
}



for(int i = 0; i < contours.size(); i++)
{
     vector<Moments> mu(contours.size() );
     vector<Point2f> mc( contours.size() );

     // Get the moments of contours
     mu[i] = moments( contours[i], false );
     //Get the centers of contours
     int cX = mu[i].m10/mu[i].m00;
     int cY = mu[i].m01/mu[i].m00;
     mc[i] = Point2f(cX, cY);

     // draw a blue circle in the center of each contour, and put the coordinates in text
     circle(frame, mc[i], 7, (255, 255, 255), -1);
     putText(frame, "Center: " + convertInt(cX) + " , " + convertInt(cY), Point2f(cX+10, cY+10), FONT_HERSHEY_SIMPLEX, 0.5, (255, 255, 255), 2);
}
