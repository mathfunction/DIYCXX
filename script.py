import sys
import os





if __name__ == '__main__':

	try:
		if sys.argv[1] == "--compile":
			cppname = sys.argv[2]
			#===================================================================================
			# 編譯腳本 !!
			cmds = [
				"g++",
				"-std=c++14",
				"-O3",
				"-o",
				cppname.split(".cpp")[0],
				cppname,
				"-I\"{}\"".format(os.path.dirname(cppname)),
				"-I./include/",
				"-I./thirdparty/boost_1_70_0",
				"-I./thirdparty/"
			]
			#===================================================================================
			cmd1 = " ".join(cmds)
			print(cmd1)
			os.system(cmd1)
		elif sys.argv[1] == "--run":
			cppname = sys.argv[2]
			os.system(cppname.split(".cpp")[0])
		else:
			pass

	except Exception as e:
		print(e)
		print("--compile [cppfile]")
		print("--run [cppfile]")