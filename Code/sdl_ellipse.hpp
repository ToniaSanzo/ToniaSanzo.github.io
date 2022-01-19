void sdl_ellipse(SDL_Renderer* r, int x0, int y0, int radiusX, int radiusY)
{
   float pih = PI / 2.0; //half of pi

   //drew  28 lines with   4x4  circle with precision of 150 0ms
   //drew 132 lines with  25x14 circle with precision of 150 0ms
   //drew 152 lines with 100x50 circle with precision of 150 3ms
   const int prec = 2; // precision value; value of 1 will draw a diamond, 27 makes pretty smooth circles.
   bool filled = true; // Whether to color the interior of the circle, the higher the precision the more fully filled the interior will be. 
   float theta = 0;    // angle that will be increased each loop

   //starting point
   int x = (float)radiusX * cos(theta);//start point
   int y = (float)radiusY * sin(theta);//start point
   int x1 = x;
   int y1 = y;

   if (filled)
   {
       SDL_RenderDrawLine(r, x0, y0, x0 + x, y0 - y);//quadrant TR
       SDL_RenderDrawLine(r, x0, y0, x0 - x, y0 - y);//quadrant TL
       SDL_RenderDrawLine(r, x0, y0, x0 - x, y0 + y);//quadrant BL
       SDL_RenderDrawLine(r, x0, y0, x0 + x, y0 + y);//quadrant BR
   }

   //repeat until theta >= 90;
   float step = pih / (float)prec; // amount to add to theta each time (degrees)

   for (theta = step; theta <= pih; theta += step)//step through only a 90 arc (1 quadrant)
   {
       //get new point location
       x1 = (float)radiusX * cosf(theta) + 0.5; //new point (+.5 is a quick rounding method)
       y1 = (float)radiusY * sinf(theta) + 0.5; //new point (+.5 is a quick rounding method)

       //draw line from previous point to new point, ONLY if point incremented
       if ((x != x1) || (y != y1))//only draw if coordinate changed
       {
           SDL_RenderDrawLine(r, x0 + x, y0 - y, x0 + x1, y0 - y1);//quadrant TR
           SDL_RenderDrawLine(r, x0 - x, y0 - y, x0 - x1, y0 - y1);//quadrant TL
           SDL_RenderDrawLine(r, x0 - x, y0 + y, x0 - x1, y0 + y1);//quadrant BL
           SDL_RenderDrawLine(r, x0 + x, y0 + y, x0 + x1, y0 + y1);//quadrant BR

           if (filled)
           {
               SDL_RenderDrawLine(r, x0, y0, x0 + x1, y0 - y1);//quadrant TR
               SDL_RenderDrawLine(r, x0, y0, x0 - x1, y0 - y1);//quadrant TL
               SDL_RenderDrawLine(r, x0, y0, x0 - x1, y0 + y1);//quadrant BL
               SDL_RenderDrawLine(r, x0, y0, x0 + x1, y0 + y1);//quadrant BR
           }
       }
       //save previous points
       x = x1;//save new previous point
       y = y1;//save new previous point
   }
   //arc did not finish because of rounding, so finish the arc
   if (x != 0)
   {
       x = 0;
       SDL_RenderDrawLine(r, x0 + x, y0 - y, x0 + x1, y0 - y1);//quadrant TR
       SDL_RenderDrawLine(r, x0 - x, y0 - y, x0 - x1, y0 - y1);//quadrant TL
       SDL_RenderDrawLine(r, x0 - x, y0 + y, x0 - x1, y0 + y1);//quadrant BL
       SDL_RenderDrawLine(r, x0 + x, y0 + y, x0 + x1, y0 + y1);//quadrant BR
   }
}