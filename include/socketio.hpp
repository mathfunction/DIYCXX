/*==========================================


============================================= */


#ifndef __SOCKETIO_HPP__ 
#define __SOCKETIO_HPP__






namespace cxxuseful{

	

	
	class AsioServer{
		private:
			string name;
			int PORT; 
			
			
			string read_from_client(boost::asio::ip::tcp::socket & socket) {  
	       		boost::asio::streambuf buf;  
	       		boost::asio::read_until(socket,buf,"\n");  
	       		string data = boost::asio::buffer_cast<const char*>(buf.data());  
	       		return data;  
			}//end_readFromClient  


			void serve_to_client(boost::asio::ip::tcp::socket &socket, const string& message){  
	       		const string msg = message;
	       		boost::asio::write(socket, boost::asio::buffer(message) );
	       		cerr << "serve_to_client : " << message << endl;   
			}//end_sendToClient  

		public:

			AsioServer(string name="First",int PORT=8888){
				this->PORT = PORT;
				this->name = name;

			}//end_Server

			void run(){
				cerr << "Server[" << this->name << "] are running !! " << endl;
				while(1){
					//==============================================
					boost::asio::io_service io_service1;
					boost::asio::ip::tcp::acceptor listener1(io_service1, boost::asio::ip::tcp::endpoint(boost::asio::ip::tcp::v4(),this->PORT));
					
					
					boost::asio::ip::tcp::socket socket1(io_service1);
					listener1.accept(socket1);
					//=================================================
					// only serve once then close the soclet
					string message = read_from_client(socket1);
					printYellow(message); 
					cerr << endl;
					serve_to_client(socket1,message);
					// ===============================================
					socket1.close();
				}//end_while
				
			}//end_run

	};



	class AsioClient{
		private:
			string name;
			int PORT; 
		public:
			AsioClient(string name="hello",int PORT=8888){
				this->PORT = PORT;
				this->name = name;
			}//end_AsioClient

			void send_to_server(boost::asio::ip::tcp::socket &socket, const string& message){
				boost::system::error_code error;  
		     	boost::asio::write(socket,boost::asio::buffer(message), error );  
		     	if(!error) {  
		          	cerr << "send_to_server : " << message << endl;  
		     	}  else {  
		          	cerr << "send_to_server failed: " << error.message() << endl;  
		     	}//end_else
			}//end_send_To_Server


			void receive_from_server(boost::asio::ip::tcp::socket & socket) {  
	       		boost::asio::streambuf receive_buffer;
	       		boost::system::error_code error;
	       		boost::asio::read(socket, receive_buffer, boost::asio::transfer_all(), error);  
	    		if( error && error != boost::asio::error::eof ) {  
	          		cerr << "receive_from_server failed: " << error.message() << endl;  
	     		}else{  
	          		const char* data = boost::asio::buffer_cast<const char*>(receive_buffer.data());  
	          		cerr << "receive_from_server : " << data << endl;  
	     		}//end_else    
			}//end_readFromClient  

			void cmdtest(string ip="127.0.0.1"){
				boost::asio::io_service io_service;
				
				string msg; 
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