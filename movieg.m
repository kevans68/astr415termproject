dirName = 'Users/kaitlinevans/astro415/Term Project';              %# folder path
files = dir( fullfile(dirName,'*.jpg') );   %# list all *.xyz files
files = {files.name}';                      %'# file names

data = cell(numel(files),1);                %# store file contents
for i=1:numel(files)
    fname = fullfile(dirName,files{i});     %# full path to file
    data{i} = myLoadFunction(fname);        %# load file
end

% create the video writer with 1 fps
 writerObj = VideoWriter('myVideo.avi');
 writerObj.FrameRate = 100;
 % set the seconds per image
 secsPerImage = [1 1 1];
 % open the video writer
 open(writerObj);
 % write the frames to the video
 for u=1:length(images{u})
     % convert the image to a frame
     frame = im2frame(images{u});
     for v=1:secsPerImage(u) 
         writeVideo(writerObj, frame);
     end
 end
 % close the writer object
 close(writerObj);