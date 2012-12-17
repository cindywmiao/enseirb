package fr.enseirb.webxml.servlet;

import java.io.IOException;
import javax.servlet.ServletException;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import fr.enseirb.webxml.util.ServletToolkit;
import java.util.Properties;

/**
 * Servlet implementation class AboutServlet
 */
public class AboutServlet extends HttpServlet {
    private static final long serialVersionUID = 1L;
   

    /**
     * @see HttpServlet#HttpServlet()
     */
    public AboutServlet() {
	super();
    }

	/**
	 * @see HttpServlet#doGet(HttpServletRequest request, HttpServletResponse response)
	 */
	protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
		String sResponse = "";
		String studentsNumber = "2";
		String student1firstName = "Miao";
		String student1lastName = "Wang";
		String student2firstName = "Louis";	    
		String student2lastName = "Boucherie";
		String groupe = "3";	    
		String classe = "I2";
		String teacher = "Mathieu Lombard";
	

		Properties params = ServletToolkit.parseURLParams(request);
		String action = params.getProperty("action");

		if (request.getRequestURI().contains("about/teacher/post")){
		    teacher = ServletToolkit.getPostData(request);
		    sResponse = teacher;
		}
		else if (request.getRequestURI().contains("about/teacher")){
		    sResponse = ServletToolkit.readFile("/resources/html/common/about_teacher.html");
		}
	

		if("studentsNumber".equals(action)) {
		    sResponse = studentsNumber;
		}else if(params.containsKey("studentId")){
		    String studentId = params.getProperty("studentId");
		    if(studentId.equals( "1")){
			if("firstName".equals(action)){
			    sResponse = student1firstName;
			}else {
			    sResponse = student1lastName;
			}
		    }
		    else{
			if("firstName".equals(action)){
			    sResponse=student2firstName;
			}else {
			    sResponse = student2lastName;
			}
		    }
		}else if ("group".equals(action)){
		    sResponse = groupe;
		}else if ("class".equals(action)){
		    sResponse = classe;
		}else if ("teacher".equals(action)){
		    sResponse = teacher;
		}else if ("full".equals(action) || "".equals(action)){
		    sResponse += "Student 1 : " + student1firstName+' '+ student1lastName + "\n";
		    sResponse += "Student 2 : " + student2firstName+' '+ student2lastName + "\n";
		    sResponse += "Class : " +  classe + "\n";
		    sResponse += "Group : " +  groupe + "\n";
		}  
		
		ServletToolkit.writeResponse(response, sResponse);
	}

	@Override
	protected void doPost(HttpServletRequest req, HttpServletResponse resp) throws ServletException, IOException {
		doGet(req, resp);
	}
}
