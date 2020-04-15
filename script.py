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
				"-std=c++11",
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
			print("[Cmd] {}".format(cmd1))
			os.system(cmd1)
		elif sys.argv[1] == "--run":
			ENTRANCE_PATH = os.getcwd()
			cppname = sys.argv[2]
			
			TARGET_PATH = os.path.dirname(cppname)
			EXEFILE = cppname.split(".cpp")[0]
			
			print("[GoTo]\t {}".format(TARGET_PATH))
			print("[Cmd] {}".format(EXEFILE))
			print("[GoBack]\t {}".format(ENTRANCE_PATH))
			# 移動到某 .cpp 專案路徑
			os.chdir(TARGET_PATH)
			os.system(EXEFILE)
			# 移動到 DIYCXX 專案路徑
			os.chdir(ENTRANCE_PATH)
			
		else:
			pass

	except Exception as e:
		print(e)
		print("--compile [cppfile]")
		print("--run [cppfile]")