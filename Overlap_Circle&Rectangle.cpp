class Solution {
public:
    bool checkOverlap(int radius, int x0, int y0, int x1, int y1, int x2, int y2) {
   
     // we are try to find  closes (x,y) corrdinate of rectangel
     // so that we can use these (x,y) coordinates as a center and makes circle
     // check actual circle is big or not

     //->  yadi (center of circle < x1)
     //->  closest point of rectangle to circle is x1 bcoz and x2>x1
     //->  else if(center of circle lies between x1 and x2)
     //->  we don't need to find closest point bcoz we are very clear , in x coordinates -> circle may be lie between
     //->  else if(center of circle > x2)
     //->  closest point of rectangle to circle is x2 bcoz and x2>x1 & x2>x1
     int diffX=max(x1,min(x2,x0));
     // simillar logic with y
     int diffY=max(y1,min(y2,y0));

     int area_of_circle_through_rectangle=(x0-diffX)*(x0-diffX)+(y0-diffY)*(y0-diffY);
     return area_of_circle_through_rectangle<=radius*radius;
           
    }
};
