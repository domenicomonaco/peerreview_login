$(document).ready(
  function() {
  
//  $("#logo-floater").addClass('cio');
  
  $(".palette-wizard").click(
    function(){
    $(".box_box").slideToggle("fast");
		$(this).toggleClass("active"); return false; 
    return false;
  });
});
