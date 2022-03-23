package edu.tntech.csc2310;

import org.jsoup.Jsoup;
import org.jsoup.nodes.Document;
import org.jsoup.nodes.Element;
import org.jsoup.select.Elements;

import java.io.IOException;
import java.util.Scanner;

@SuppressWarnings("SpellCheckingInspection")
public class Course {

    private static final String url = "https://ttuss1.tntech.edu/PROD/bwckctlg.p_disp_course_detail?";
    private String subject;
    private String number;
    private String title;
    private String description;
    private String rawDescription;
    private int credits;
    private String[] prerequisites;

    public Course(String subject, String number, String term) throws CourseNotFoundException {

        /**
         * Modify this method so that it throws a CourseNotFoundException if the course does
         * not exist.
         */

        String subj = subject.trim().toUpperCase();
        String numb = number.trim();
        Integer trm = Integer.parseInt(term.trim());
        Integer numbTest = Integer.parseInt(numb);

        String searchUrl = url + "&cat_term_in=" + trm.toString() + "&subj_code_in=" + subj + "&crse_numb_in=" + numbTest.toString();
        try {
            Document doc = Jsoup.connect(searchUrl).get();
            Elements elements = doc.select(".nttitle");
            if (elements.size() > 0) {
                String temp = (String) elements.get(0).text();
                int index = temp.indexOf('-');
                this.title = temp.substring(index + 2);

                Elements courseDescription = doc.select(".ntdefault");
                this.rawDescription = courseDescription.get(0).text();
                this.credits = (int) this.parseCRH();
                this.subject = subj;
                this.number = numb;
                this.prerequisites = this.getPrerequisites();
                this.description = this.filterDescription(this.rawDescription);
            } else { // Course Not Found
                throw new CourseNotFoundException("Course " + subj + " " + numb + " not found.");
//                this.subject = null;
//                this.description = null;
//                this.number = null;
//                this.credits = -1;
            }
        } catch (IOException e) {
            e.printStackTrace();
        }
    }

    private double parseCRH(){
        int index = this.rawDescription.indexOf("Credit hours");
        String tmp = this.rawDescription.substring(0, index-1);
        int first = tmp.lastIndexOf(" ");
        int idx = Math.max(first, 0);
        tmp = tmp.substring(idx).trim();
        return Double.parseDouble(tmp);
    }

    private String filterDescription(String s){

        String result = s.replaceAll(".000","");
        int idx = result.lastIndexOf("Prerequisites");
        if (idx > 0)
            result = result.substring(0,idx);
        return result;
    }

    public String getSubject() {
        return subject;
    }

    public String getNumber() {
        return number;
    }

    public String getTitle() {
        return title;
    }

    public String getDescription() {
        return description;
    }

    /**
     * Creates a flattened list of pre-requisites; removes C or D or better information,
     * as well as disjunctive normal form. All structure should be removed from the pre-requisite list
     * @return
     */
    public String[] getPrerequisites() {

        String[] repls = {
                "Course or Test: ",
                "Minimum Grade of C ",
                "Minimum Grade of D ",
                "May not be taken concurrently.",
                "May be taken concurrently.",
                "(",
                ")"
                };

        String[] list = null;
        if (this.rawDescription != null) {
            int sindex = this.rawDescription.lastIndexOf("Requirements:");
            if (sindex > 0) {
                String subStr = this.rawDescription.substring(sindex + 13).trim();
                for (int i = 0; i < repls.length; i++) {
                    subStr = subStr.replace(repls[i], "");
                }
                subStr = subStr.replace("or", ",");
                subStr = subStr.replace("and", ",");
                list = subStr.split(",");
                String[] trimmed = new String[list.length];
                for (int i = 0; i < list.length; i++) {
                    trimmed[i] = list[i].trim();
                }
                list = trimmed;
            }
        }
        return list;
    }

    public int getCredits() {
        return credits;
    }

    public String toString(){
        return subject + " " + number + " " + title + "\n" + description;
    }

    public String toString(boolean full){
        if (full)
            return this + this.description;
        else
            return this.toString();
    }

    private static void log(String msg, String... vals) {
        System.out.println(String.format(msg, vals));
    }

}
