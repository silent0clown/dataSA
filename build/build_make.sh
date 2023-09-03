# 返回脚本文件放置的目录
cd $(dirname $0)

CURRENT_PATH=$(pwd)
SRC_PATH=$CURRENT_PATH/"../src/"

if [ $CMAKE ];then
	echo "CMAKE = $CMAKE"
else
  CMAKE=cmake
# 查看cmake version info
$CMAKE --version

# output path
OUT_PATH=$CURRENT_PATH/"../output"/
BUILD_PATH=$OUT_PATH/"Release"
rm -rf $OUT_PATH
mkdir -p $BUILD_PATH
# pushd $BUILD_PATH > /dev/null

fi
# -B        指定构建的项目文件所在的目录
# -G        Generator 的意思，该语句可以设置 IDE
$CMAKE .. -DCMAKE_INSTALL_PREFIX=$BUILD_PATH -G "Unix Makefiles"

make install