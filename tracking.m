function d = tracking(video)

if ischar(video)
    % ??????
    for i = 1 : avi.NumberOfFrames
        img = read(avi, i);
        pixels(:, :, :, i) = img;       %pixels???4D??
    end
else
    pixels = video;
end

nFrames = size(pixels, 4);              %pixels??4????????
rows = size(pixels, 1);                 %pixels??1??????????
cols = size(pixels, 2);                 %pixels??2??????????

% ???????
for i = 1 : nFrames
    pixel(:, :, i) = (rgb2gray(pixels(:,:,:,i)));   %??3????????
end

for i = 2 : nFrames
    % ????
    d(:, :, i) = (abs(pixel(:,:,i) - pixel(:,:,i-1)));
    
    %?????????????????????
    bw(:, :, i) = im2bw(d(:, :, i), 0.2);
    
    % ??????
    cou=1;
    for h = 1:rows
        for w = 1:cols
            if bw(h, w, i) > 0.5
                bottomEdge = h;
                if cou == 1
                    topEdge = bottomEdge;
                end
                cou = cou+1;
                break;
            end
        end
    end

    % ??????
    coun=1;
    for w = 1:cols
        for h = 1:rows
            if bw(h, w, i) > 0.5
                rightEdge =w;
                if coun == 1
                    leftEdge = rightEdge;
                    coun = coun+1;
                end
                break;
            end
        end
    end

    % ?????
    wd = rightEdge-leftEdge;
    hg = bottomEdge-topEdge;
    widt = wd/2;
    heit = hg/2;
    cenx = leftEdge+widt;
    ceny = topEdge+heit;
    
    cenx1(i-1)=cenx;        % ???????????????????
    ceny1(i-1)=ceny;
    
    if i > 3
        s = struct('dx',0,'dy',0,'flagx',1,'flagy',1);
        s.dx = cenx1(i-1) - cenx1(i-2);
        s.dy = ceny1(i-1) - ceny1(i-2);
        if s.dx < 0 
            s.flagx = 2;
        end
        if s.dy < 0
            s.flagy = 2;
        end
        s.dx = abs(s.dx);
        s.dy = abs(s.dy);
        disp(s);
    end
    
    
    % ?????
    figure(1);
    imshow(pixels(:, :, :, i), []);         %?????
    hold on
    rectangle('Position',[leftEdge topEdge wd hg], 'EdgeColor', 'r', 'LineWidth', 2);
    plot(cenx1,ceny1, 'm-.s','MarkerSize',7, 'LineWidth', 1)    % ??????????
    
    text(3, 15, sprintf('?????%d? By GLF', i), 'FontWeight', 'Bold', 'Color', 'r');
    hold off
end

