/*==========================================


============================================= */


#ifndef __SOCKETIO_HPP__ 
#define __SOCKETIO_HPP__






namespace cxxuseful{

	

	
	class AsioServer{
		private:
			std::string name;
			int PORT; 
			
			
			std::string read_from_client(boost::asio::ip::tcp::socket & socket) {  
	       		boost::asio::streambuf buf;  
	       		boost::asio::read_until(socket,buf,"\n");  
	       		std::string data = boost::asio::buffer_cast<const char*>(buf.data());  
	       		return data;  
			}//end_readFromClient  


			void serve_to_client(boost::asio::ip::tcp::socket &socket, const std::string& message){  
	       		const std::string msg = message;
	       		boost::asio::write(socket, boost::asio::buffer(message) );
	       		std::cerr << "serve_to_client : " << message << std::endl;   
			}//end_sendToClient  

		public:

			AsioServer(std::string name="First",int PORT=8888){
				this->PORT = PORT;
				this->name = name;

			}//end_Server

			void run(){
				std::cerr << "Server[" << this->name << "] are running !! " << std::endl;
				while(1){
					//==============================================
					boost::asio::io_service io_service1;
					boost::asio::ip::tcp::acceptor listener1(io_service1, boost::asio::ip::tcp::endpoint(boost::asio::ip::tcp::v4(),this->PORT));
					
					
					boost::asio::ip::tcp::socket socket1(io_service1);
					listener1.accept(socket1);
					//=================================================
					// only serve once then close the soclet
					std::string message = read_from_client(socket1);
					printYellow(message); 
					std::cerr << std::endl;
					serve_to_client(socket1,message);
					// ===============================================
					socket1.close();
				}//end_while
				
			}//end_run

	};



	class AsioClient{
		private:
			std::string name;
			int PORT; 
		public:
			AsioClient(std::string name="hello",int PORT=8888){
				this->PORT = PORT;
				this->name = name;
			}//end_AsioClient

			void send_to_server(boost::asio::ip::tcp::socket &socket, const std::string& message){
				boost::system::error_code error;  
		     	boost::asio::write(socket,boost::asio::buffer(message), error );  
		     	if(!error) {  
		          	std::cerr << "send_to_server : " << message << std::endl;  
		     	}  else {  
		          	std::cerr << "send_to_server failed: " << error.message() << std::endl;  
		     	}//end_else
			}//end_send_To_Server


			void receive_from_server(boost::asio::ip::tcp::socket & socket) {  
	       		boost::asio::streambuf receive_buffer;
	       		boost::system::error_code error;
	       		boost::asio::read(socket, receive_buffer, boost::asio::transfer_all(), error);  
	    		if( error && error != boost::asio::error::eof ) {  
	          		std::cerr << "receive_from_server failed: " << error.message() << std::endl;  
	     		}else{  
	          		const char* data = boost::asio::buffer_cast<const char*>(receive_buffer.data());  
	          		std::cerr << "receive_from_server : " << data << std::endl;  
	     		}//end_else    
			}//end_readFromClient  

			void cmdtest(std::string ip="127.0.0.1"){
				boost::asio::io_service io_service;
				
				std::string msg; 
				while(cin >> msg){
					boost::asio::ip::tcp::socket socket1(io_service);
					socket1.connect( boost::asio::ip::tcp::endpoint(boost::asio::ip::address::from_string(ip),this->PORT)); 
		     		send_to_server(socket1,msg+"\n");
		     		receive_from_server(socket1);
		     		socket1.close();
	     		}//end_while
	     		
			}//end_run


	};
	









};













#endif 