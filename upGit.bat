del /p /f node_modules
git init
git add .
git commit -m "git images"
git branch -M master
git remote add origin git@github.com:chauity/blog.git
git push -u origin master --force

pause