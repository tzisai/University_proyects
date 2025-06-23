import java.io.*;
import javax.servlet.*;
import javax.servlet.http.*;

public class LoginServlet extends HttpServlet {
    protected void doPost(HttpServletRequest request, HttpServletResponse response) 
            throws ServletException, IOException {
        String usuario = request.getParameter("usuario");
        String contrasena = request.getParameter("contrasena");

        response.setContentType("text/html");
        PrintWriter out = response.getWriter();

        if ("admin".equals(usuario) && "1234".equals(contrasena)) {
            out.println("<h2>Bienvenido " + usuario + "</h2>");
        } else {
            out.println("<h2>Usuario o contraseña incorrectos</h2>");
        }
    }
}
