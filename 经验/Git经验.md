# Git 经验记录

## 首次推送本地项目到 GitHub

### 1. 初始化本地仓库
```bash
git init
```

### 2. 添加远程仓库
```bash
git remote add origin git@github.com:MerZlin/LeetCodeStudy.git
```

### 3. 创建 .gitignore
忽略不需要版本控制的文件（编译产物、IDE 配置等）。

### 4. 暂存并提交
```bash
git add -A
git commit -m "Initial commit: LeetCode solutions"
```

### 5. 处理分支名
GitHub 新建仓库默认分支是 `main`，如果本地是 `master`，需要重命名：
```bash
git branch -m master main
```

### 6. 推送到远程
```bash
git push -u origin main
```

## SSH 认证测试
```bash
ssh -T git@github.com
```
成功会显示：`Hi <username>! You've successfully authenticated, but GitHub does not provide shell access.`
（注意：这条消息的退出码是 1，这是正常的，不代表失败）

## 常见问题

### 远程已有内容时的冲突处理
如果远程仓库不是空的（有 README、LICENSE 等），需要先拉取合并：
```bash
git pull origin main --allow-unrelated-histories
```

### LF/CRLF 换行符警告
Windows 下 Git 会自动转换换行符，属于正常现象。如需统一使用 LF：
```bash
git config core.autocrlf input
```
