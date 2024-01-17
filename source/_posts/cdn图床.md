---
title:  免费图床CDN加速
date: 2024-01-05 14:17:59
tags: 图床 + cdn + picgo
categories: jsDilivr, pic
---
# 工具
- `VSCode PicGo` 
- `GitHub` 
- `jsDelivr`
# 步骤
## GitHub配置
- `VSCode`安装`PicGo插件`

![pic1](https://gcore.jsdelivr.net/gh/chauity/xximgxx/24-imgs/20240105142927.png)
 
- 新建`GitHub`仓库，获取相关`PicGo`配置参数

``` code
{
  "repo": "", // 仓库名，格式是username/reponame
  "token": "", // github token
  "path": "", // 自定义存储路径，比如img/
  "customUrl": "", // 自定义域名，注意要加http://或者https://
  "branch": "" // 分支名，默认是main
}
```
- 访问 `https://github.com/settings/tokens`，点击 `Generate new token`
 ![](https://gcore.jsdelivr.net/gh/chauity/xximgxx/24-imgs/20240105152138.png)
- 新增`token`
 ![](https://gcore.jsdelivr.net/gh/chauity/xximgxx/24-imgs/20240105153031.png)

- 之后拉到最底点击绿色按钮`Generate token`,记住这个`token`
![](https://gcore.jsdelivr.net/gh/chauity/xximgxx/24-imgs/20240105153643.png)

## PicGo配置
- 打开`VSCode`设置,搜索`picgo`
![](https://gcore.jsdelivr.net/gh/chauity/xximgxx/24-imgs/20240105154256.png)

## 测试上传
- `Win系统`上传剪切板截图快捷键是`ctrl + alt + u`
![20240105155319](https://gcore.jsdelivr.net/gh/chauity/xximgxx/24-imgs/20240105155319.png)

## CDN加速
- `VSCode`设置中配置`customUrl`(自定义域名)

`https://gcore.jsdelivr.net/gh/你的用户名/你的仓库名/`

![20240105160612](https://gcore.jsdelivr.net/gh/chauity/xximgxx/24-imgs/20240105160612.png)

- 这里面的用到的是`jsdelivr`，有时候可能会访问不到，一共有三个IP可以作为`CDN`地址加速,分别是

``` http
https://cdn.jsdelivr.net/gh/你的用户名/你的仓库名/
https://fastly.jsdelivr.net/gh/你的用户名/你的仓库名/
https://gcore.jsdelivr.net/gh/你的用户名/你的仓库名/
```
- 使用`https://tcping8.com/ping/`可以查看多地的cdn加速情况
![20240108101021](https://gcore.jsdelivr.net/gh/chauity/xximgxx/24-imgs/20240108101021.png)




