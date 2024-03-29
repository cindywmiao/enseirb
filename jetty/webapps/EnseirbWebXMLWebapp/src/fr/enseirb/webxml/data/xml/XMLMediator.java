package fr.enseirb.webxml.data.xml;

import java.io.IOException;
import java.text.ParseException;
import java.text.SimpleDateFormat;
import java.util.Date;
import java.util.HashMap;
import java.util.Iterator;
import java.util.List;
import java.util.Map;
import java.util.logging.Level;
import java.util.logging.Logger;

import org.w3c.dom.Document;
import org.w3c.dom.Element;
import org.w3c.dom.NodeList;

import fr.enseirb.webxml.data.dao.DBManager;
import fr.enseirb.webxml.data.model.Task;
import fr.enseirb.webxml.data.model.User;
import fr.enseirb.webxml.util.ServletToolkit;
import fr.enseirb.webxml.util.XMLToolkit;

public class XMLMediator {
	private static final Logger LOGGER = Logger.getLogger(XMLMediator.class.getName());

	public static final SimpleDateFormat DATE_FORMAT = new SimpleDateFormat("dd/MM/yyyy");

	public static final String createEmptyTaskXML() {
		StringBuilder buffer = new StringBuilder(XMLToolkit.XML_HEADER);
		appendTaskXML(new Task(), buffer);
		return buffer.toString();
	}

	private static final void appendTaskXML(Task task, StringBuilder buffer) {
		buffer.append("<task id=\"").append(task.getId()).append("\" ");
		buffer.append("title=\"").append(task.getTitle()).append("\" ");
		buffer.append("creationDate=\"").append(DATE_FORMAT.format(task.getCreationDate())).append("\" ");
		buffer.append("deadline=\"").append(DATE_FORMAT.format(task.getDeadline())).append("\" ");
		buffer.append("priority=\"").append(task.getPriority()).append("\" ");
		buffer.append("done=\"").append(Boolean.toString(task.isDone())).append("\">");
		buffer.append("<description>").append(task.getDescription()).append("</description>");
		buffer.append("<asker>").append(task.getAsker()).append("</asker>");
		buffer.append("<owner>").append(task.getOwner()).append("</owner>");
		buffer.append("</task>");
	}

	/*
	 * <tasks> <task id="xxx" title="ttt" deadline="dd/MM/yyyy" priority="123" done="true">
	 * <description>ddd</description> <asker>aaa</asker> <owner>ooo</owner> </task> <task id="yyy" title="ttt"
	 * deadline="dd/MM/yyyy" priority="123" done="false"> <description>ddd</description> <asker>aaa</asker>
	 * <owner>ooo</owner> </task> ... </tasks>
	 */
	public static String getTasks() {
		List<Task> tasks = DBManager.INSTANCE.getTaskDAO().getTasks();

		// TODO : creer le flux XML correspondant aux taches
		String tasksXML = "";
		LOGGER.log(Level.INFO, "XML Tasks are: " + tasksXML);
		return tasksXML;
	}

	public static String getTask(int id) {
		Task task = DBManager.INSTANCE.getTaskDAO().getTask(id);
		
		// TODO : creer le flux XML correspondant a la tache demandee
		String taskXML = "";
		LOGGER.log(Level.INFO, "XML Task with id " + id + " is: " + taskXML);
		return taskXML;
	}

	/*
	 * <task id="xxx" title="ttt" deadline="dd/MM/yyyy" priority="123" done="true"> <description>ddd</description>
	 * <asker>aaa</asker> <owner>ooo</owner> </task>
	 */
	public static boolean addOrModifyTask(String taskXML) {
		LOGGER.log(Level.INFO, "Adding or modifying Task stream: " + taskXML);

		Document doc = XMLToolkit.parseDocument(taskXML);
		Element taskElt = doc.getDocumentElement();
		return addOrModifyTask(taskElt);
	}

	public static boolean addOrModifyTask(Element taskElt) {
		LOGGER.log(Level.INFO, "Adding or modifying Task element");

		boolean success;
		try {
			Task task = new Task();

			// TODO completer la creation de l'objet Task
			// pour la date, utiliser le code ci-dessous
			task.setDeadline(DATE_FORMAT.parse(taskElt.getAttribute("deadline")));
			
			success = DBManager.INSTANCE.getTaskDAO().addOrModify(task);
			if (success) {
				// on rajoute les utilisateurs au passage
				DBManager.INSTANCE.getUserDAO().addUser(new User(task.getAsker()));
				DBManager.INSTANCE.getUserDAO().addUser(new User(task.getOwner()));
			}
		} catch (ParseException e) {
			LOGGER.log(Level.INFO, "Problem while adding or modifying", e);
			success = false;
		}

		return success;
	}

	/*
	 * <users> <user name="xxx"/> <user name="yyy"/> ... </users>
	 */
	public static String getUsers() {
		List<User> users = DBManager.INSTANCE.getUserDAO().getUsers();

		// TODO renvoyer le flux XML correspondant a la liste des utilisateurs
		String usersXML = "";
		LOGGER.log(Level.INFO, "XML Users are: " + usersXML);
		return usersXML;
	}

	/*
	 * <user name="xxx"/>
	 */
	public static boolean addUser(String userXML) {
		LOGGER.log(Level.INFO, "Adding User stream: " + userXML);

		Document doc = XMLToolkit.parseDocument(userXML);
		Element userElt = doc.getDocumentElement();
		return addUser(userElt);
	}

	public static boolean addUser(Element userElt) {
		LOGGER.log(Level.INFO, "Adding User element: ");
		
		// TODO : remplir la variable "name" avec la valeur de l'attribut "name" de userElt
		String name = "";
		User user = new User(name);
		
		return DBManager.INSTANCE.getUserDAO().addUser(user);
	}

	public static String buildStats() {
		LOGGER.log(Level.INFO, "Building stats");
		String users = getUsers();
		String tasks = getTasks();

		String now = DATE_FORMAT.format(new Date());
		String day = now.substring(0, 2);
		String month = now.substring(3, 5);
		String year = now.substring(6, 10);

		String nowDate = year + month + day;
		String xPathDate = "concat(substring(@deadline,7,4), substring(@deadline,4,2), substring(@deadline,1,2))";

		// TODO : creer un flux XML pour les stats
		
		String statsXML = "";
		LOGGER.log(Level.INFO, "Stats built: " + statsXML);
		return statsXML;
	}

	public static boolean parseInitDB(String initDBPath) {
		LOGGER.log(Level.INFO, "Parsing init DB file: " + initDBPath);

		String initDBStream;
		try {
			initDBStream = ServletToolkit.readFile(initDBPath);
		} catch (IOException e) {
			LOGGER.log(Level.SEVERE, "Error while parsing init DB file");
			initDBStream = null;
		}

		if (initDBStream != null) {
			return importXMLTasks(initDBStream);
		} else {
			return false;
		}
	}

	public static boolean importXMLTasks(String initDBStream) {
		LOGGER.log(Level.INFO, "Importing tasks");

		boolean success;
		try {
//			if (!XMLToolkit.isXMLValid(initDBStream, "/resources/xsd/db_dump.xsd")) {
//				throw new Exception("Init file is not valid against XMLSchema");
//			}

			Document doc = XMLToolkit.parseDocument(initDBStream);
			Element rootElt = doc.getDocumentElement();

			NodeList tasksNodes = rootElt.getElementsByTagName("tasks");
			if (tasksNodes.getLength() > 1) {
				throw new Exception("More than 1 <tasks> element");
			}

			NodeList usersNodes = rootElt.getElementsByTagName("users");
			if (tasksNodes.getLength() > 1) {
				throw new Exception("More than 1 <users> element");
			}

			if (tasksNodes.getLength() == 1) {
				// on ajoute les taches
				Element tasksNode = (Element) tasksNodes.item(0);
				NodeList taskNodes = tasksNode.getElementsByTagName("task");
				for (int i = 0; i < taskNodes.getLength(); i++) {
					Element taskNode = (Element) taskNodes.item(i);
					if (!addOrModifyTask(taskNode)) {
						throw new Exception("Error while adding task");
					}
				}
			}

			if (usersNodes.getLength() == 1) {
				// on ajoute les users
				Element usersNode = (Element) usersNodes.item(0);
				NodeList userNodes = usersNode.getElementsByTagName("user");
				for (int i = 0; i < userNodes.getLength(); i++) {
					Element userNode = (Element) userNodes.item(i);
					if (!addUser(userNode)) {
						throw new Exception("Error while adding user");
					}
				}
			}

			success = true;
		} catch (IOException e) {
			LOGGER.log(Level.INFO, "Error while importing data in db", e);
			success = false;
		} catch (Exception e) {
			LOGGER.log(Level.INFO, "Error while importing data in db", e);
			success = false;
		}

		return success;
	}

}
