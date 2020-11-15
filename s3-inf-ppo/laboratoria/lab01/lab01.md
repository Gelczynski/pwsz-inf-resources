Cd /
mkdir ppo
cd ppo
mkdir 123456
cd 123456

git init
git remote add origin https://github.com/krzysztofrewak/pwsz-in resources.git
git pull origin master
git status

git config user.name = "Student Studencki"
git config user.email = "student@example.com"

git add .
git status
git commit -am „zmiany”
git push origin master
