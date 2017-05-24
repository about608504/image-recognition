clc;
clear all;
% ?????
avi = VideoReader('/Users/bcy/Documents/MATLAB/test.avi');

% ?????
for i = 1 : avi.NumberOfFrames
    img = read(avi, i);
    pixels(:, :, :, i) = img;           %pixels???4D??
  figure(1); imshow(img, []);
    text(3, 15, sprintf(' ????%d ? By GLF', i), 'FontWeight', 'Bold', 'Color', 'r');
    tracking(pixels);
    pause(0.2)
    drawnow
end

% ??????
tracking(pixels);