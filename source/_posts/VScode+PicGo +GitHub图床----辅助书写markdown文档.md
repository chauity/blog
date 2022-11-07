---
title: VScode+PicGo +GitHub图床----辅助书写markdown文档
---

# VScode + GitHub + PicGo + Statically

## 说明

本文将介绍，如何使用VScode安装picGo插件。将图片上传至GitHub的图床中，将使用到Staticlly的CDN加速，方便国内查看。

建议：
免费图床虽好，切勿滥用，如果有条件的话，可以选择国内的OSS和COS等云服务器搭建。GitHub国内加速CDN已经封了jsdelivr了，请谨慎使用statically。建议一个库不超过1G，，一张图片不要超过15M。超过了，就建立其他的库。否则可能会有封号的风险。

## 第一步：安装VScode、配置PicGo

国内可以选择腾讯软件中心下载：https://pc.qq.com/detail/16/detail_22856.html

官网是：https://code.visualstudio.com/Download

下载插件PicGo、Chinese、GitHub Theme、markdownlint、Office Viewer
![20221107110904](https://cdn.staticaly.com/gh/chauity/images@master/blog/pictrues20221107110904.png)

上面是我使用VScode的一些插件，VScode还是挺好用的。如果只是写一些md文档，不使用远程图床工具本地使用的话，可以选择其他工具。我之前使用的是typedown，这个工具有一个很大的缺陷就是不能直接粘贴图片，付费的话也可以选择typero。

配置PicGo远程图床
![20221107111319](https://cdn.staticaly.com/gh/chauity/images@master/blog/pictrues20221107111319.png)

![20221107145751](https://cdn.staticaly.com/gh/chauity/images@master/blog/pictures/20221107145751.png)


## 第二步：GitHub的设置

### 1）配置密钥

在GitHub里面的注册账号，并点击头像下面设置
如果无法进入GitHub，就下载一个Steam++或者UU加速器学术资源加速。
![20221107134300](https://cdn.staticaly.com/gh/chauity/images@master/blog/pictures/20221107134300.jpg)

下滑到最下面找到 `Developer settings`,点击进入
![20221107134455](https://cdn.staticaly.com/gh/chauity/images@master/blog/pictures/20221107134455.jpg)

点击 `Personal access tokens`下面的 `Tokens(classic)`
![20221107134529](https://cdn.staticaly.com/gh/chauity/images@master/blog/pictures/20221107134529.jpg)

点击 `Generate new token`，创建密钥
![20221107134802](https://cdn.staticaly.com/gh/chauity/images@master/blog/pictures/20221107134802.jpg)

![20221107134953](https://cdn.staticaly.com/gh/chauity/images@master/blog/pictures/20221107134953.jpg)

这里的密钥就是上面配置PicGo需要的密钥。

### 2）创建仓库

回到GitHub首页，点击 `New`按钮
![20221107135217](https://cdn.staticaly.com/gh/chauity/images@master/blog/pictures/20221107135217.jpg)

![20221107140047](https://cdn.staticaly.com/gh/chauity/images@master/blog/pictures/20221107140047.jpg)

配置完成后点击，Create repository，就创建好了仓库了。

## 完成，使用

这里就配置好了，大家使用markdown文档时，打开VScode时。

直接使用 `Ctrl + Alt + U`键就能粘贴且上传到GitHub里面。
