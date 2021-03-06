import sys
import os





if __name__ == '__main__':

	try:
		if sys.argv[1] == "--compile":
			cppname = sys.argv[3]
			#===================================================================================
			# 編譯腳本 !!
			cmds = [
				"g++",
				"-std={}".format(sys.argv[2]),
				"-static",
				"-mavx",
				"-mavx2",
				"-march=native",
				"-Xpreprocessor",
				"-fopenmp",
				"-O3",
				"-o",
				cppname.split(".cpp")[0],
				cppname,
				"-I\"{}\"".format(os.path.dirname(cppname)),
				"-I./include/",
				"-I./thirdparty/boost_1_70_0",
                #"-I./thirdparty/websocketpp",
                "-I./thirdparty/"
			]
			#===================================================================================
			
			cmd1 = " ".join(cmds)
			print("[Cmd] {}".format(cmd1))
			os.system(cmd1)
		
		elif sys.argv[1] == "--compile-cuda":
			cuname = sys.argv[3]
			#===================================================================================
			# 編譯腳本 !!
			cmds = [
				"nvcc",
				"-O3",
				"-o",
				cuname.split(".cu")[0],
				cuname,
				"-I\"{}\"".format(os.path.dirname(cuname)),
				"-I./include/",
				"-I./thirdparty/boost_1_70_0",
                "-I./thirdparty/websocketpp",
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

		elif sys.argv[1] == "--run-cuda":
			ENTRANCE_PATH = os.getcwd()
			cppname = sys.argv[2]
			
			TARGET_PATH = os.path.dirname(cppname)
			EXEFILE = cppname.split(".cu")[0]
			
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
		print("--compile {c++11,c++14,c++17,c++20} [cppfile] ")
		print("--compile-cuda {c++11,c++14} [cufile]")
		print("--run [cppfile]")
		print("--run-cuda [cufile]")
