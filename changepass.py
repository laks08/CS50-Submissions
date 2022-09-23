# @app.route("/changepass", methods=["GET", "POST"])
# def register():
#     """Register user"""
#     if request.method == "GET":
#         return render_template("changepass.html")
#     else:
#         username = request.form.get("username")
#         oldpass = request.form.get("oldpass")
#         newpass = request.form.get("newpass")
#         confnewpass = request.form.get("confnewpass")

#         if not username:
#             return apology("Error: Username Needed")

#         if not oldpass:
#             return apology("Error: Enter Old Password")

#         if not newpass:
#             return apology("Error: Enter New Password")

#         if not confnewpass:
#             return apology("Error: Enter New Password Again")

#         if newpass != confnewpass:
#             return apology("Passwords Don't Match")

#         # Query database for username
#         rows1 = db.execute("SELECT * FROM users WHERE username = ?", request.form.get("username"))

#         # Ensure username exists and password is correct
#         if len(rows1) != 1 or not check_password_hash(rows1[0]["hash"], request.form.get("oldpass")):
#             return apology("invalid username and/or password", 403)

#         new_hash = generate_pasword_hash(newpass)

#         try:
#             change_pass = db.execute("UPDATE users SET hash = ? WHERE username = ?", new_hash, username)

#         except:
#             return apology("SAME PASSWORD. TRY AGAIN")

#         return redirect("/")


