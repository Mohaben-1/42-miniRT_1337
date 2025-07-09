/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohaben- <mohaben-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/08 17:47:31 by mohaben-          #+#    #+#             */
/*   Updated: 2025/07/08 20:23:36 by mohaben-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERRORS_H
# define ERRORS_H

// General Errors
# define ERR_REQUIRED1 "Error\nScene file must contain exactly one Ambient (A)"
# define ERR_REQUIRED2 ", one Camera (C), and one Light (L) definition.\n"
# define ERR_FD1 "Error\nFailed to open the file: "
# define ERR_FD2 "file not found or permission denied\n"

// Ambient
# define ERR_ARGS_AMBIENT1 "Error\nInvalid Ambient light: "
# define ERR_ARGS_AMBIENT2 "expected format 'A ratio R,G,B'\n"
# define ERR_RATIO_AMBIENT1 "Error\nInvalid ambient light ratio: "
# define ERR_RATIO_AMBIENT2 "must be a float between 0.0 and 1.0\n"
# define ERR_COLOR_ABMIENT1 "Error\nInvalid ambient light color: expected "
# define ERR_COLOR_ABMIENT2 "format 'R,G,B' with values between 0 and 255\n"

// Camera
# define ERR_ARGS_CAM1 "Error\nInvalid camera: "
# define ERR_ARGS_CAM2 "expected format 'C x,y,z x,y,z FOV'.\n"
# define ERR_POSITION_CAM1 "Error\nInvalid camera position: "
# define ERR_POSITION_CAM2 "expected format 'x,y,z' with numeric values.\n"
# define ERR_DIR_CAM1 "Error\nInvalid camera direction: must be a normalized "
# define ERR_D_C2 "vector 'x,y,z' where each component is between -1 and 1.\n"
# define ERR_FOV_CAM1 "Error\nInvalid field of view: "
# define ERR_FOV_CAM2 "FOV must be a number between 0 and 180 degrees.\n"

// Light
# define ERR_ARGS_L1 "Error\nInvalid light: "
# define ERR_ARGS_L2 "expected format 'L x,y,z brightness R,G,B'\n"
# define ERR_POS_L1 "Error\nInvalid light position: "
# define ERR_POS_L2 "expected a 3D vector 'x,y,z' with numeric values.\n"
# define ERR_BRIGHT_L1 "Error\nInvalid light brightness: "
# define ERR_BRIGHT_L2 "expected a float between 0.0 and 1.0.\n"
# define ERR_COLOR_L1 "Error\nInvalid light color: "
# define ERR_COLOR_L2 "expected RGB format 'r,g,b' between 0 and 255.\n"

// Sphere
# define ERR_ARGS_S1 "Error\nInvalid sphere: "
# define ERR_ARGS_S2 "expected format 'sp x,y,z diameter r,g,b'\n"
# define ERR_POS_S1 "Error\nInvalid sphere position: "
# define ERR_POS_S2 "expected 'x,y,z' with numeric values.\n"
# define ERR_DIAMETER_S1 "Error\nInvalid sphere diameter: "
# define ERR_DIAMETER_S2 "expected a positive floating-point number.\n"
# define ERR_COLOR_S1 "Error\nInvalid sphere color: "
# define ERR_COLOR_S2 "expected RGB format 'r,g,b' between 0 and 255.\n"

// Cylinder
# define ERR_ARGS_CY1 "Error\nInvalid cylinder: expected format "
# define ERR_ARGS_CY2 "'cy center_x,y,z axis_x,y,z diameter height r,g,b'\n"
# define ERR_POS_CY1 "Error\nInvalid cylinder position: "
# define ERR_POS_CY2 "expected 'x,y,z' with numeric values.\n"
# define ERR_NORMALE_CY1 "Error\nInvalid cylinder axis vector: "
# define ERR_NORMALE_CY2 "must be normalized 'x,y,z' between -1 and 1.\n"
# define ERR_DIAMTR_CY1 "Error\nInvalid cylinder diameter: "
# define ERR_DIAMTR_CY2 "expected a positive floating-point number.\n"
# define ERR_HEIGHT_CY1 "Error\nInvalid cylinder height: "
# define ERR_HEIGHT_CY2 "expected a positive floating-point number.\n"
# define ERR_COLOR_CY1 "Error\nInvalid cylinder color: "
# define ERR_COLOR_CY2 "expected RGB format 'r,g,b' between 0 and 255.\n"

// Plane
# define ERR_ARGS_P1 "Error\nInvalid plane: expected "
# define ERR_ARGS_P2 "format 'pl x,y,z normal_x,normal_y,normal_z r,g,b'\n"
# define ERR_POS_P1 "Error\nInvalid plane position: "
# define ERR_POS_P2 "expected 'x,y,z' with numeric values.\n"
# define ERR_NORMAL_P1 "Error\nInvalid plane normal vector: "
# define ERR_NORMAL_P2 "must be normalized 'x,y,z' between -1 and 1.\n"
# define ERR_COLOR_P1 "Error\nInvalid plane color: "
# define ERR_COLOR_P2 "expected RGB format 'r,g,b' between 0 and 255.\n"

#endif