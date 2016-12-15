xyf = fopen('galaxy_lf.dat');
xy = dlmread('galaxy_lf.dat');
i = 1;
% while ~feof(xyf)

% figure()
% plot(xy(i*1:500,1),xy(i*1:500,2),'.')
% hold on
% plot(xy(i*501:end,1),xy(i*501:end,2),'.')
% xlabel('x');
% ylabel('y');

%while ~feof(xyf)

% figure()
% scatter3(xy(i*1:500,2),xy(i*1:500,3),xy(i*1:500,4),'.')
% hold on 
% scatter3(xy(i*501:1000*i,2),xy(i*501:1000*i,3),xy(i*501:1000*i,4),'.')
% xlabel('x');
% ylabel('y');
% zlabel('z');
% hold off 
% 
% i = i+1;
% 
% end 
    h = 0;
   for i = 1: length(xy)
       while(xy(i,1)) == (0 + h)
           if xy(i,2) <= 0 
               figure()
               scatter3(xy(i,2),xy(i,3),xy(i,4),'r')
               hold on
           else 
               scatter3(xy(i,2),xy(i,3),xy(i,4),'c')
           end 
       end 
       
       hold off 
       h = h+.65    
       
   end 
    
       
   
 
 
    
    